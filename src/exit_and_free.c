/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:42:49 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 17:36:41 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_two_d(char **map_two_d)
{
	int	i;

	if (!map_two_d)
		return ;
	i = 0;
	while ((map_two_d)[i])
	{
		free((map_two_d)[i]);
		i++;
	}
	free(map_two_d);
}

void	error_message(char *error)
{
	printf("%s", error);
}

void	free_all(t_all_struct *cub_map, int flag, char *error)
{
	if (error)
		error_message(error);
	if (cub_map)
	{
		if (cub_map->map.real_map_two_d)
			free_two_d(cub_map->map.real_map_two_d);
		if (cub_map->map.map_two_d)
			free_two_d(cub_map->map.map_two_d);
		if (cub_map->map.map_one_d)
			free(cub_map->map.map_one_d);
		if (cub_map->map.real_map_one_d)
			free(cub_map->map.real_map_one_d);
	}
	if (cub_map->game.mlx)
		delete_mlx(cub_map);
	if (cub_map->game.mlx)
	{
		mlx_terminate(cub_map->game.mlx);
		cub_map->game.mlx = NULL;
	}
	if (flag)
		exit(EXIT_FAILURE);
}
