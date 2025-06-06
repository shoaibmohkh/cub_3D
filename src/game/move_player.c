/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:54:02 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 18:17:12 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	touch(float px, float py, t_all_struct *cub_map)
{
	int	x;
	int	y;

	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	if (x < 0 || y < 0 || !cub_map->game.map[y] || !cub_map->game.map[y][x])
		return (1);
	return (cub_map->game.map[y][x] == '1');
}

static void	calculate_movement_deltas(t_all_struct *cub_map, float move_speed,
		float *dx, float *dy)
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

void	handle_player_movement(t_all_struct *cub_map, float move_speed,
		float *new_x, float *new_y)
{
	float	dx;
	float	dy;

	dx = 0;
	dy = 0;
	calculate_movement_deltas(cub_map, move_speed, &dx, &dy);
	*new_x += dx;
	*new_y += dy;
}
