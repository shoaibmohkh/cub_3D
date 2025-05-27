/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:56:36 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 18:17:46 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint32_t	*pixel;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	pixel = (uint32_t *)img->pixels + (y * WIDTH + x);
	*pixel = color;
}

void	draw_half_screen(t_all_struct *cub_map, int start_y, int end_y,
		uint32_t color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(cub_map->game.img, x, y, color);
			x++;
		}
		y++;
	}
}

void	fill_background(t_all_struct *cub_map)
{
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	int			half_height;

	ceiling_color = (0xFF << 24)
		| (cub_map->map.ceiling_color[2] << 16)
		| (cub_map->map.ceiling_color[1] << 8)
		| cub_map->map.ceiling_color[0];
	floor_color = (0xFF << 24)
		| (cub_map->map.floor_color[2] << 16)
		| (cub_map->map.floor_color[1] << 8)
		| cub_map->map.floor_color[0];
	half_height = HEIGHT / 2;
	draw_half_screen(cub_map, 0, half_height, ceiling_color);
	draw_half_screen(cub_map, half_height, HEIGHT, floor_color);
}
