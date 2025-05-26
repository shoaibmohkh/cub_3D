/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:49:30 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 20:17:24 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extract_path(t_all_struct *cub_map, int i, int j, char *dest)
{
	int	path;

	if (cub_map->map.num_paths == 0)
		cub_map->map.index_north_line_no = j;
	else if (cub_map->map.num_paths == 1)
		cub_map->map.index_south_line_so = j;
	else if (cub_map->map.num_paths == 2)
		cub_map->map.index_west_line_we = j;
	else if (cub_map->map.num_paths == 3)
		cub_map->map.index_east_line_ea = j;
	j += 2;
	while (cub_map->map.map_two_d[i][j] == ' '
		|| cub_map->map.map_two_d[i][j] == '\t')
		j++;
	path = 0;
	while (cub_map->map.map_two_d[i][j] && cub_map->map.map_two_d[i][j] != ' '
		&& cub_map->map.map_two_d[i][j] != '\t')
		dest[path++] = cub_map->map.map_two_d[i][j++];
	dest[path] = '\0';
	cub_map->map.num_paths++;
	return (j);
}

int	is_valid_path_line(char **map_line, int j, char *id)
{
	while ((*map_line)[j] == ' ' || (*map_line)[j] == '\t')
		j++;
	if ((*map_line)[j] == id[0] && (*map_line)[j + 1] == id[1] && ((*map_line)[j
			+ 2] == ' ' || (*map_line)[j + 2] == '\t'))
		return (1);
	return (0);
}

void	check_path(t_all_struct *cub_map, t_path_info *path_info)
{
	int	i;
	int	j;

	i = 0;
	while (cub_map->map.map_two_d[i] && i < cub_map->map.start_of_map)
	{
		j = 0;
		if (is_valid_path_line(&cub_map->map.map_two_d[i], j, path_info->id))
		{
			j = extract_path(cub_map, i, j, path_info->dest);
			while (cub_map->map.map_two_d[i][j] == ' '
				|| cub_map->map.map_two_d[i][j] == '\t')
				j++;
			if (cub_map->map.map_two_d[i][j] != '\0')
				break ;
			return ;
		}
		i++;
	}
	free_all(cub_map, 1, path_info->error_msg);
}
