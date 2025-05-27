/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:54:02 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 16:44:33 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	touch(float px, float py, t_all_struct *cub_map)
{
    int	x = (int)(px / BLOCK);
    int	y = (int)(py / BLOCK);

    if (x < 0 || y < 0 || !cub_map->game.map[y] || !cub_map->game.map[y][x])
        return (1);
    return (cub_map->game.map[y][x] == '1');
}

void	handle_player_movement(t_all_struct *cub_map, float move_speed,
        float *new_x, float *new_y)
{
    float	dx = 0;
    float	dy = 0;
    if (cub_map->player.key_up)
    {
        dx += cosf(cub_map->player.angle) * move_speed;
        dy += sinf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_down)
    {
        dx -= cosf(cub_map->player.angle) * move_speed;
        dy -= sinf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_left)
    {
        dx += sinf(cub_map->player.angle) * move_speed;
        dy -= cosf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_right)
    {
        dx -= sinf(cub_map->player.angle) * move_speed;
        dy += cosf(cub_map->player.angle) * move_speed;
    }
    *new_x += dx;
    *new_y += dy;
}

void	move_player(t_all_struct *cub_map)
{
    float	move_speed = 1.0f;
    float	rot_speed = 0.02f;
    float	new_x = cub_map->player.x;
    float	new_y = cub_map->player.y;
    float	dx = 0;
    float	dy = 0;
    if (cub_map->player.key_up)
    {
        dx += cosf(cub_map->player.angle) * move_speed;
        dy += sinf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_down)
    {
        dx -= cosf(cub_map->player.angle) * move_speed;
        dy -= sinf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_left)
    {
        dx += sinf(cub_map->player.angle) * move_speed;
        dy -= cosf(cub_map->player.angle) * move_speed;
    }
    if (cub_map->player.key_right)
    {
        dx -= sinf(cub_map->player.angle) * move_speed;
        dy += cosf(cub_map->player.angle) * move_speed;
    }
    if (!touch(new_x + dx, new_y, cub_map))
        new_x += dx;
    if (!touch(new_x, new_y + dy, cub_map))
        new_y += dy;
    cub_map->player.x = new_x;
    cub_map->player.y = new_y;
    if (cub_map->player.left_rotate)
        cub_map->player.angle -= rot_speed;
    if (cub_map->player.right_rotate)
        cub_map->player.angle += rot_speed;
    cub_map->player.angle = fmodf(cub_map->player.angle, 2 * M_PI);
    if (cub_map->player.angle < 0)
        cub_map->player.angle += 2 * M_PI;
}
