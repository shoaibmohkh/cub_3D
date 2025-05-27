/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:54:02 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 18:16:35 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	handle_player_movement_input(t_all_struct *cub_map, float *dx,
		float *dy, float move_speed)
{
	if (cub_map->player.key_up)
	{
		*dx += cosf(cub_map->player.angle) * move_speed;
		*dy += sinf(cub_map->player.angle) * move_speed;
	}
	if (cub_map->player.key_down)
	{
		*dx -= cosf(cub_map->player.angle) * move_speed;
		*dy -= sinf(cub_map->player.angle) * move_speed;
	}
	if (cub_map->player.key_left)
	{
		*dx += sinf(cub_map->player.angle) * move_speed;
		*dy -= cosf(cub_map->player.angle) * move_speed;
	}
	if (cub_map->player.key_right)
	{
		*dx -= sinf(cub_map->player.angle) * move_speed;
		*dy += cosf(cub_map->player.angle) * move_speed;
	}
}

static void	update_player_position(t_all_struct *cub_map, float dx, float dy)
{
	float	new_x;
	float	new_y;

	new_x = cub_map->player.x;
	new_y = cub_map->player.y;
	if (!touch(new_x + dx, new_y, cub_map))
		new_x += dx;
	if (!touch(new_x, new_y + dy, cub_map))
		new_y += dy;
	cub_map->player.x = new_x;
	cub_map->player.y = new_y;
}

static void	update_player_rotation(t_all_struct *cub_map, float rot_speed)
{
	if (cub_map->player.left_rotate)
		cub_map->player.angle -= rot_speed;
	if (cub_map->player.right_rotate)
		cub_map->player.angle += rot_speed;
	cub_map->player.angle = fmodf(cub_map->player.angle, 2 * M_PI);
	if (cub_map->player.angle < 0)
		cub_map->player.angle += 2 * M_PI;
}

void	move_player(t_all_struct *cub_map)
{
	float	move_speed;
	float	rot_speed;
	float	dx;
	float	dy;

	move_speed = 1.0f;
	rot_speed = 0.02f;
	dx = 0;
	dy = 0;
	handle_player_movement_input(cub_map, &dx, &dy, move_speed);
	update_player_position(cub_map, dx, dy);
	update_player_rotation(cub_map, rot_speed);
}
