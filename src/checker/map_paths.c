/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:49:30 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 15:40:37 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extract_path(t_all_struct *cub_map, int i, int j, char *dest, int *index)
{
	int	path;

	*index = j;
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

void	check_path(t_all_struct *cub_map, char *id, char *dest, int *index,
		char *error_msg)
{
	int	i;
	int	j;

	i = 0;
	while (cub_map->map.map_two_d[i] && i < cub_map->map.start_of_map)
	{
		j = 0;
		while (cub_map->map.map_two_d[i][j] == ' '
			|| cub_map->map.map_two_d[i][j] == '\t')
			j++;
		if (cub_map->map.map_two_d[i][j] == id[0] && cub_map->map.map_two_d[i][j
			+ 1] == id[1] && (cub_map->map.map_two_d[i][j + 2] == ' '
			|| cub_map->map.map_two_d[i][j + 2] == '\t'))
		{
			j = extract_path(cub_map, i, j, dest, index);
			while (cub_map->map.map_two_d[i][j] == ' '
				|| cub_map->map.map_two_d[i][j] == '\t')
				j++;
			if (cub_map->map.map_two_d[i][j] != '\0')
				break ;
			return ;
		}
		i++;
	}
	free_all(cub_map, 1, error_msg);
}

void	check_north_path(t_all_struct *cub_map)
{
	check_path(cub_map, "NO", cub_map->map.path_north_no,
		&cub_map->map.index_north_line_no,
		"\033[1;31merror in MAP\033[0m 😤\n");
}

void	check_south_path(t_all_struct *cub_map)
{
	check_path(cub_map, "SO", cub_map->map.path_south_so,
		&cub_map->map.index_south_line_so,
		"\033[1;31merror in MAP\033[0m😤\n");
}

void	check_west_path(t_all_struct *cub_map)
{
	check_path(cub_map, "WE", cub_map->map.path_west_we,
		&cub_map->map.index_west_line_we,
		"\033[1;31merror in MAP\033[0m 😤\n");
}

void	check_east_path(t_all_struct *cub_map)
{
	check_path(cub_map, "EA", cub_map->map.path_east_ea,
		&cub_map->map.index_east_line_ea,
		"\033[1;31merror in MAP\033[0m 😤\n");
}
