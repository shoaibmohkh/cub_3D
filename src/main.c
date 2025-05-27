/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:07:46 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 14:59:11 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	map_checker(t_all_struct *cub_map)
{
	floor_color(cub_map);
	ceiling_color(cub_map);
	check_north_path(cub_map);
	check_south_path(cub_map);
	check_west_path(cub_map);
	check_east_path(cub_map);
	check_befor_real_map(cub_map);
	check_chararcters(cub_map);
	wall_checker(cub_map, cub_map->map.start_of_map);
	last_wall_checker(cub_map);
	mid_wall_checker(cub_map);
	if (!ft_check_map_validity(cub_map))
		free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
}

int	map(t_all_struct *cub_map, int argc, char **argv)
{
	int	fd;

	if (input_checker(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("\033[1;31merror in MAP\033[0m 😤\n");
		return (1);
	}
	get_map(cub_map, fd);
	map_checker(cub_map);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all_struct	cub_map;

	ft_bzero(&cub_map, sizeof(t_all_struct));
	if (map(&cub_map, argc, argv))
		return (1);
	init_game(&cub_map);
	mlx_key_hook(cub_map.game.mlx, key_handler, &cub_map);
	mlx_loop_hook(cub_map.game.mlx, game_loop, &cub_map);
	mlx_loop(cub_map.game.mlx);
	free_all(&cub_map, 0, NULL);
	mlx_terminate(cub_map.game.mlx);
	return (0);
}
