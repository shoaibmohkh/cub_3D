/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:41:51 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/20 17:00:47 by sal-kawa         ###   ########.fr       */
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
		free_all(cub_map, 1, "not a valid map");
}

int	map(t_all_struct *cub_map, int argc, char **argv)
{
	int	fd;

	if (input_checker(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("\033[1;31mwrong argumet: can't open it\033[0m ⛓️‍💥\n");
		exit(1);
	}
	get_map(cub_map, fd);
	map_checker(cub_map);
	print_struct(cub_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all_struct	cub_map;

	ft_bzero(&cub_map, sizeof(t_all_struct));
	if (map(&cub_map, argc, argv))
		return (1);
	printf("fdfd\n");
	return (0);
}
