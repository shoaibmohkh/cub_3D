/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:56:36 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/24 20:12:04 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void fill_background(t_all_struct *cub_map)
{
    uint32_t ceiling_color;
    uint32_t floor_color;
    int half_height;
    int x;
    int y;

    ceiling_color = (0xFF << 24) |
                    (cub_map->map.ceiling_color[2] << 16) |
                    (cub_map->map.ceiling_color[1] << 8) |
                    cub_map->map.ceiling_color[0];
    floor_color = (0xFF << 24) |
                  (cub_map->map.floor_color[2] << 16) |
                  (cub_map->map.floor_color[1] << 8) |
                  cub_map->map.floor_color[0];
    half_height = HEIGHT / 2;
    y = 0;
    while (y < half_height)
    {
        x = 0;
        while (x < WIDTH)
        {
            put_pixel(cub_map->game.img, x, y, ceiling_color);
            x++;
        }
        y++;
    }
    y = half_height;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            put_pixel(cub_map->game.img, x, y, floor_color);
            x++;
        }
        y++;
    }
}

void put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
    uint32_t *pixel = NULL;
    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    pixel = (uint32_t *)img->pixels + (y * WIDTH + x);
    *pixel = color;
}