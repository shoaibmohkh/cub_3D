/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:55:40 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 17:36:25 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_all_struct *cub_map)
{
	cub_map->player.x = cub_map->map.x_player * BLOCK + BLOCK / 2;
	cub_map->player.y = cub_map->map.y_player * BLOCK + BLOCK / 2;
	if (cub_map->map.start_direction_of_player == 'S')
		cub_map->player.angle = M_PI / 2;
	else if (cub_map->map.start_direction_of_player == 'N')
		cub_map->player.angle = 3 * M_PI / 2;
	else if (cub_map->map.start_direction_of_player == 'W')
		cub_map->player.angle = M_PI;
	else if (cub_map->map.start_direction_of_player == 'E')
		cub_map->player.angle = 0;
}

void	key_press(mlx_key_data_t keydata, t_all_struct *cub_map)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		cub_map->player.key_up = 1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		cub_map->player.key_up = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		cub_map->player.key_down = 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		cub_map->player.key_down = 0;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		cub_map->player.key_left = 1;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		cub_map->player.key_left = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		cub_map->player.key_right = 1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		cub_map->player.key_right = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		cub_map->player.left_rotate = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		cub_map->player.left_rotate = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		cub_map->player.right_rotate = 1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		cub_map->player.right_rotate = 0;
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_all_struct	*cub_map;

	cub_map = (t_all_struct *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub_map->game.mlx);
	key_press(keydata, cub_map);
}
