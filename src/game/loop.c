/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:53:00 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 15:11:15 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	game_loop(void *param)
{
	t_all_struct	*cub_map;
	float			fraction;
	float			start_x;
	int				i;

	cub_map = (t_all_struct *)param;
	fill_background(cub_map);
	move_player(cub_map);
	fraction = M_PI / 3 / WIDTH;
	start_x = cub_map->player.angle - M_PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(cub_map, start_x, i);
		start_x = start_x + fraction;
		i = i + 1;
	}
}

int	load_texture(t_texture *tex, mlx_t *mlx, char *path, t_all_struct *cub_map)
{
	tex->texture = mlx_load_png(path);
	if (!tex->texture)
	{
		free_all(cub_map, 1, "\033[1;31merror in MLX\033[0m 😤\n");
		return (0);
	}
	tex->img = mlx_texture_to_image(mlx, tex->texture);
	if (!tex->img)
	{
		mlx_delete_texture(tex->texture);
		free_all(cub_map, 1, "\033[1;31merror in MLX\033[0m 😤\n");
		return (0);
	}
	tex->width = tex->texture->width;
	tex->height = tex->texture->height;
	return (1);
}

void	init_game(t_all_struct *cub_map)
{
	cub_map->game.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!cub_map->game.mlx)
		free_all(cub_map, 1, "\033[1;31merror in MLX\033[0m 😤\n");
	cub_map->game.img = mlx_new_image(cub_map->game.mlx, WIDTH, HEIGHT);
	if (!cub_map->game.img)
		free_all(cub_map, 1, "\033[1;31merror in MLX\033[0m 😤\n");
	if (mlx_image_to_window(cub_map->game.mlx, cub_map->game.img, 0, 0) < 0)
		free_all(cub_map, 1, "\033[1;31merror in MLX\033[0m 😤\n");
	cub_map->game.map = cub_map->map.real_map_two_d;
	cub_map->game.all_struct = cub_map;
	if (!load_texture(&cub_map->game.north, cub_map->game.mlx,
			cub_map->map.path_north_no, cub_map))
		return ;
	if (!load_texture(&cub_map->game.south, cub_map->game.mlx,
			cub_map->map.path_south_so, cub_map))
		return ;
	if (!load_texture(&cub_map->game.east, cub_map->game.mlx,
			cub_map->map.path_east_ea, cub_map))
		return ;
	if (!load_texture(&cub_map->game.west, cub_map->game.mlx,
			cub_map->map.path_west_we, cub_map))
		return ;
	init_player(cub_map);
}

void	cleanup(t_all_struct *cub_map)
{
	if (cub_map->game.north.texture)
		mlx_delete_texture(cub_map->game.north.texture);
	if (cub_map->game.north.img)
		mlx_delete_image(cub_map->game.mlx, cub_map->game.north.img);
	if (cub_map->game.south.texture)
		mlx_delete_texture(cub_map->game.south.texture);
	if (cub_map->game.south.img)
		mlx_delete_image(cub_map->game.mlx, cub_map->game.south.img);
	if (cub_map->game.east.texture)
		mlx_delete_texture(cub_map->game.east.texture);
	if (cub_map->game.east.img)
		mlx_delete_image(cub_map->game.mlx, cub_map->game.east.img);
	if (cub_map->game.west.texture)
		mlx_delete_texture(cub_map->game.west.texture);
	if (cub_map->game.west.img)
		mlx_delete_image(cub_map->game.mlx, cub_map->game.west.img);
}
