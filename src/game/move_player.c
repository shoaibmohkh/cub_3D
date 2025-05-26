/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:54:02 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 13:34:36 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool touch(float px, float py, t_all_struct *cub_map)
{
    int x;
    int y;

    x = px / BLOCK;
    y = py / BLOCK;
    if (x < 0 || y < 0 || !cub_map->game.map[y] || !cub_map->game.map[y][x])
        return (true);
    return (cub_map->game.map[y][x] == '1');
}

void move_player(t_all_struct *cub_map)
{
    float move_speed;
    float rot_speed;
    float new_x;
    float new_y;

    move_speed = 8.0f;
    rot_speed = 0.02f;
    new_x = cub_map->player.x;
    new_y = cub_map->player.y;
    if (cub_map->player.key_up)
    {
        new_x += cosf(cub_map->player.angle) * move_speed;
        new_y += sinf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_down)
    {
        new_x -= cosf(cub_map->player.angle) * move_speed;
        new_y -= sinf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_left)
    {
        new_x += sinf(cub_map->player.angle) * move_speed;
        new_y -= cosf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_right)
    {
        new_x -= sinf(cub_map->player.angle) * move_speed;
        new_y += cosf(cub_map->player.angle) * move_speed;
    }
    if (!touch(new_x, new_y, cub_map))
    {
        cub_map->player.x = new_x;
        cub_map->player.y = new_y;
    }
    if (cub_map->player.left_rotate)
        cub_map->player.angle -= rot_speed;
    if (cub_map->player.right_rotate)
        cub_map->player.angle += rot_speed;
    cub_map->player.angle = fmodf(cub_map->player.angle, 2 * M_PI);
    if (cub_map->player.angle < 0)
        cub_map->player.angle += 2 * M_PI;
}
