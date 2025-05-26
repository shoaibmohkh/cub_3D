/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:52:09 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 17:45:39 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	distance(float x, float y)
{
	float	result;

	result = sqrtf(x * x + y * y);
	return (result);
}

float	fixed_dist(t_fpoint from, t_fpoint to, float angle)
{
	float	delta_x;
	float	delta_y;
	float	diff_angle;

	delta_x = to.x - from.x;
	delta_y = to.y - from.y;
	diff_angle = atan2f(delta_y, delta_x) - angle;
	return (distance(delta_x, delta_y) * cosf(diff_angle));
}

void	init_ray(t_ray *ray, t_all_struct *cub_map, float angle)
{
	ray->x = cub_map->player.x;
	ray->y = cub_map->player.y;
	ray->dir_x = cosf(angle);
	ray->dir_y = sinf(angle);
}

void	init_deltas(t_cast *cast, t_ray *ray)
{
	cast->map_x = (int)(ray->x / BLOCK);
	cast->map_y = (int)(ray->y / BLOCK);
	if (ray->dir_x == 0)
		cast->delta_x = 1e30;
	else
		cast->delta_x = BLOCK / fabsf(ray->dir_x);
	if (ray->dir_y == 0)
		cast->delta_y = 1e30;
	else
		cast->delta_y = BLOCK / fabsf(ray->dir_y);
}
