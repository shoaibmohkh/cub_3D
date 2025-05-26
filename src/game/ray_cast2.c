/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:52:09 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 17:45:46 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_steps(t_cast *cast, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		cast->step_x = -1;
		cast->side_x = (ray->x - cast->map_x * BLOCK) / -ray->dir_x;
	}
	else
	{
		cast->step_x = 1;
		cast->side_x = ((cast->map_x + 1) * BLOCK - ray->x) / ray->dir_x;
	}
	if (ray->dir_y < 0)
	{
		cast->step_y = -1;
		cast->side_y = (ray->y - cast->map_y * BLOCK) / -ray->dir_y;
	}
	else
	{
		cast->step_y = 1;
		cast->side_y = ((cast->map_y + 1) * BLOCK - ray->y) / ray->dir_y;
	}
}

void	perform_dda(t_cast *cast, t_all_struct *cub)
{
	while (1)
	{
		if (cast->side_x < cast->side_y)
		{
			cast->side_x += cast->delta_x;
			cast->map_x += cast->step_x;
			cast->side = 0;
		}
		else
		{
			cast->side_y += cast->delta_y;
			cast->map_y += cast->step_y;
			cast->side = 1;
		}
		if (cast->map_x < 0 || cast->map_y < 0 || !cub->game.map[cast->map_y]
			|| !cub->game.map[cast->map_y][cast->map_x]
			|| cub->game.map[cast->map_y][cast->map_x] == '1')
			break ;
	}
}

int	check_hit(t_cast *c, t_all_struct *cub)
{
	return (c->map_x >= 0 && c->map_y >= 0 && cub->game.map[c->map_y]
		&& cub->game.map[c->map_y][c->map_x]
		&& cub->game.map[c->map_y][c->map_x] == '1');
}

float	compute_angle_and_distance(t_cast *c, t_ray *r, t_all_struct *cub)
{
	float	diff;

	diff = cub->player.angle - atan2f(r->dir_y, r->dir_x);
	while (diff > M_PI)
		diff -= 2 * M_PI;
	while (diff < -M_PI)
		diff += 2 * M_PI;
	if (c->side == 0)
	{
		if (c->step_x > 0)
			c->distance = (c->map_x * BLOCK - r->x) / r->dir_x;
		else
			c->distance = ((c->map_x + 1) * BLOCK - r->x) / r->dir_x;
	}
	else
	{
		if (c->step_y > 0)
			c->distance = (c->map_y * BLOCK - r->y) / r->dir_y;
		else
			c->distance = ((c->map_y + 1) * BLOCK - r->y) / r->dir_y;
	}
	return (diff);
}

void	compute_wall_diff_and_distance(t_cast *c, t_ray *r, t_all_struct *cub)
{
	float	diff;

	diff = compute_angle_and_distance(c, r, cub);
	if (c->distance < 0.1f)
		c->distance = 0.1f;
	c->perp_dist = c->distance * cosf(diff);
	if (c->perp_dist < 0.1f)
		c->perp_dist = 0.1f;
}
