/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:16:51 by zsalah            #+#    #+#             */
/*   Updated: 2025/05/26 20:19:30 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_north_path(t_all_struct *cub_map)
{
	t_path_info	info;

	info.id = "NO";
	info.dest = cub_map->map.path_north_no;
	info.index = &cub_map->map.index_north_line_no;
	info.error_msg = "\033[1;31merror in MAP\033[0m 😤\n";
	check_path(cub_map, &info);
}

void	check_south_path(t_all_struct *cub_map)
{
	t_path_info	info;

	info.id = "SO";
	info.dest = cub_map->map.path_south_so;
	info.index = &cub_map->map.index_south_line_so;
	info.error_msg = "\033[1;31merror in MAP\033[0m😤\n";
	check_path(cub_map, &info);
}

void	check_west_path(t_all_struct *cub_map)
{
	t_path_info	info;

	info.id = "WE";
	info.dest = cub_map->map.path_west_we;
	info.index = &cub_map->map.index_west_line_we;
	info.error_msg = "\033[1;31merror in MAP\033[0m 😤\n";
	check_path(cub_map, &info);
}

void	check_east_path(t_all_struct *cub_map)
{
	t_path_info	info;

	info.id = "EA";
	info.dest = cub_map->map.path_east_ea;
	info.index = &cub_map->map.index_east_line_ea;
	info.error_msg = "\033[1;31merror in MAP\033[0m 😤\n";
	check_path(cub_map, &info);
}
