/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:52:42 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/28 14:26:58 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_square(mlx_image_t *img, int x, int y, int size, uint32_t color, float scale)
{
    int scaled_size = (int)(size * scale);
    int i = 0;
    int j = 0;

    while (j < scaled_size)
    {
        i = 0;
        while (i < scaled_size)
        {
            put_pixel(img, x + i, y + j, color);
            i++;
        }
        j++;
    }
}

void draw_minimap(t_all_struct *cub_map)
{
    int offset_x = 5;
    int offset_y = 5;
    int border = 5;
    int max_size = 150;
    int w = 0;
    int h = 0;

    if (!cub_map || !cub_map->game.map || !cub_map->game.map[0] || !cub_map->game.img)
        return;
    while (cub_map->game.map[h])
    {
        int len = 0;
        while (cub_map->game.map[h][len])
            len++;
        if (len > w)
            w = len;
        h++;
    }
    float scale_x = (float)(max_size - 2 * border) / (w * BLOCK);
    float scale_y = (float)(max_size - 2 * border) / (h * BLOCK);
    float scale = fminf(scale_x, scale_y);

    int block_mini = (int)(BLOCK * scale);
    int w_mini = w * block_mini + 2 * border;
    int h_mini = h * block_mini + 2 * border;

    int y = offset_y;
    while (y < offset_y + h_mini)
    {
        int x = offset_x;
        while (x < offset_x + w_mini)
        {
            if (y < offset_y + border || y >= offset_y + h_mini - border ||
                x < offset_x + border || x >= offset_x + w_mini - border)
                put_pixel(cub_map->game.img, x, y, 0xFFFFFFFF);
            else
                put_pixel(cub_map->game.img, x, y, 0x333333FF);
            x++;
        }
        y++;
    }
    y = 0;
    while (cub_map->game.map[y])
    {
        int x = 0;
        while (cub_map->game.map[y][x])
        {
            if (cub_map->game.map[y][x] == '1')
            {
                draw_square(cub_map->game.img,
                            offset_x + border + x * block_mini,
                            offset_y + border + y * block_mini,
                            block_mini, 0xFFFFA500, 1.0f);
            }
            x++;
        }
        y++;
    }
    int player_tile_x = (int)(cub_map->player.x / BLOCK);
    int player_tile_y = (int)(cub_map->player.y / BLOCK);
    if (player_tile_x >= 0 && player_tile_x < w && player_tile_y >= 0 && player_tile_y < h &&
        cub_map->game.map[player_tile_y][player_tile_x] != '1')
    {
        float rel_x = (cub_map->player.x - player_tile_x * BLOCK) / BLOCK;
        float rel_y = (cub_map->player.y - player_tile_y * BLOCK) / BLOCK;

        int px = offset_x + border + (int)(player_tile_x * block_mini + rel_x * block_mini);
        int py = offset_y + border + (int)(player_tile_y * block_mini + rel_y * block_mini);
        int psize = fmax(3, block_mini / 4);
        draw_square(cub_map->game.img, px - psize / 2, py - psize / 2, psize, 0xFF0000FF, 1.0f);
    }
}