/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:52:09 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/24 20:29:51 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float distance(float x, float y)
{
    float result;

    result = sqrtf(x * x + y * y);
    return (result);
}

float fixed_dist(float x1, float y1, float x2, float y2, t_all_struct *cub_map)
{
    float delta_x;
    float delta_y;
    float angle;
    float fix_dist;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    angle = atan2f(delta_y, delta_x) - cub_map->player.angle;
    fix_dist = distance(delta_x, delta_y) * cosf(angle);
    return (fix_dist);
}

void draw_line(t_all_struct *cub_map, float ray_angle, int i)
{
    float ray_x;
    float ray_y;
    float ray_dir_x;
    float ray_dir_y;
    float side_dist_x;
    float side_dist_y;
    float delta_dist_x;
    float delta_dist_y;
    float ray_distance;
    float angle_diff;
    float perp_wall_dist;
    float height;
    float wall_x;
    float step;
    float tex_pos;
    int map_x;
    int map_y;
    int step_x;
    int step_y;
    int side;
    int start_y;
    int end_y;
    int tex_x;
    int tex_y;
    int y;
    t_texture *tex;
    uint32_t color;

    ray_x = cub_map->player.x;
    ray_y = cub_map->player.y;
    ray_dir_x = cosf(ray_angle);
    ray_dir_y = sinf(ray_angle);

    map_x = (int)(ray_x / BLOCK);
    map_y = (int)(ray_y / BLOCK);

    delta_dist_x = (ray_dir_x == 0) ? 1e30 : (BLOCK / fabsf(ray_dir_x));
    delta_dist_y = (ray_dir_y == 0) ? 1e30 : (BLOCK / fabsf(ray_dir_y));

    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (ray_x - map_x * BLOCK) / (-ray_dir_x);
    }
    else
    {
        step_x = 1;
        side_dist_x = ((map_x + 1) * BLOCK - ray_x) / ray_dir_x;
    }

    if (ray_dir_y < 0)
    {
        step_y = -1;
        side_dist_y = (ray_y - map_y * BLOCK) / (-ray_dir_y);
    }
    else
    {
        step_y = 1;
        side_dist_y = ((map_y + 1) * BLOCK - ray_y) / ray_dir_y;
    }

    while (1)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1;
        }

        if (map_x < 0 || map_y < 0 || !cub_map->game.map[map_y] || !cub_map->game.map[map_y][map_x] || cub_map->game.map[map_y][map_x] == '1')
            break;
    }

    if (map_x >= 0 && map_y >= 0 && cub_map->game.map[map_y] && cub_map->game.map[map_y][map_x] && cub_map->game.map[map_y][map_x] == '1')
    {
        if (side == 0)
        {
            float wall_x_world = (step_x > 0) ? (map_x * BLOCK) : ((map_x + 1) * BLOCK);
            ray_distance = (wall_x_world - cub_map->player.x) / ray_dir_x;
        }
        else
        {
            float wall_y_world = (step_y > 0) ? (map_y * BLOCK) : ((map_y + 1) * BLOCK);
            ray_distance = (wall_y_world - cub_map->player.y) / ray_dir_y;
        }

        if (ray_distance < 0.1f)
            ray_distance = 0.1f;

        angle_diff = ray_angle - cub_map->player.angle;
        while (angle_diff > M_PI)
            angle_diff -= 2 * M_PI;
        while (angle_diff < -M_PI)
            angle_diff += 2 * M_PI;

        perp_wall_dist = ray_distance * cosf(angle_diff);
        if (perp_wall_dist < 0.1f)
            perp_wall_dist = 0.1f;

        height = (BLOCK / perp_wall_dist) * (HEIGHT / 2.0f);
        height = fminf(height, HEIGHT);
        height = fmaxf(height, 1.0f);

        start_y = (HEIGHT - (int)height) / 2;
        end_y = start_y + (int)height;

        if (start_y < 0)
            start_y = 0;
        if (end_y > HEIGHT)
            end_y = HEIGHT;

        if (side == 0 && ray_dir_x > 0)
            tex = &cub_map->game.east;
        else if (side == 0 && ray_dir_x <= 0)
            tex = &cub_map->game.west;
        else if (side == 1 && ray_dir_y > 0)
            tex = &cub_map->game.south;
        else
            tex = &cub_map->game.north;

        if (side == 0)
        {
            float hit_y = cub_map->player.y + ray_distance * ray_dir_y;
            wall_x = fmodf(hit_y / BLOCK, 1.0f);
        }
        else
        {
            float hit_x = cub_map->player.x + ray_distance * ray_dir_x;
            wall_x = fmodf(hit_x / BLOCK, 1.0f);
        }

        if (wall_x < 0)
            wall_x += 1.0f;

        tex_x = (int)(wall_x * tex->width);
        if (side == 0 && ray_dir_x > 0)
            tex_x = tex->width - tex_x - 1;
        else if (side == 1 && ray_dir_y < 0)
            tex_x = tex->width - tex_x - 1;

        if (tex_x < 0)
            tex_x = 0;
        if (tex_x >= tex->width)
            tex_x = tex->width - 1;

        float full_wall_height = (BLOCK / perp_wall_dist) * (HEIGHT / 2.0f);
        step = (float)tex->height / full_wall_height;
        tex_pos = ((start_y - HEIGHT / 2 + full_wall_height / 2)) * step;

        y = start_y;
        while (y < end_y)
        {
            tex_y = (int)tex_pos;
            if (tex_y < 0)
                tex_y = 0;
            if (tex_y >= tex->height)
                tex_y = tex->height - 1;

            color = *(uint32_t *)(tex->texture->pixels + (tex_y * tex->width + tex_x) * 4);
            if ((color & 0xFF) != 0)
                put_pixel(cub_map->game.img, i, y, color);

            tex_pos += step;
            y++;
        }
    }
}
