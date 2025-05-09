/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:49:30 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/08 23:52:55 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extract_north_path(t_all_struct *cub_map, int i, int j)
{
	int	path;

	cub_map->map.index_north_line_no = j;
	j += 2;
	while (cub_map->map.map_two_d[i][j] == 32
		|| cub_map->map.map_two_d[i][j] == 9)
		j++;
	path = 0;
	while (cub_map->map.map_two_d[i][j] && cub_map->map.map_two_d[i][j] != 32
		&& cub_map->map.map_two_d[i][j] != 9)
		cub_map->map.path_north_no[path++] = cub_map->map.map_two_d[i][j++];
	cub_map->map.path_north_no[path++] = '\0';
	cub_map->map.num_paths++;
	return (j);
}

void	check_north_path(t_all_struct *cub_map)
{
	int	i;
	int	j;

	i = 0;
	while (cub_map->map.map_two_d[i] && (i < cub_map->map.start_of_map))
	{
		j = 0;
		while (cub_map->map.map_two_d[i][j] == 32
			|| cub_map->map.map_two_d[i][j] == 9)
			j++;
		if (cub_map->map.map_two_d[i][j] == 'N' && cub_map->map.map_two_d[i][j + 1] == 'O'
            && (cub_map->map.map_two_d[i][j + 2] == 32
			|| cub_map->map.map_two_d[i][j + 2] == 9))
		{
			j = extract_north_path(cub_map, i, j);
			while (cub_map->map.map_two_d[i][j] == 32
				|| cub_map->map.map_two_d[i][j] == 9)
				j++;
			if (cub_map->map.map_two_d[i][j] != '\0')
				break ;
			return ;
		}
		i++;
	}
	free_all(cub_map, 1,
			"\033[1;31mMissed path:\033[0m there is no north path 😤\n");
}

int	extract_south_path(t_all_struct *cub_map, int i, int j)
{
	int	path;

	cub_map->map.index_south_line_so = j;
	j += 2;
	while (cub_map->map.map_two_d[i][j] == 32
		|| cub_map->map.map_two_d[i][j] == 9)
		j++;
	path = 0;
	while (cub_map->map.map_two_d[i][j] && cub_map->map.map_two_d[i][j] != 32
		&& cub_map->map.map_two_d[i][j] != 9)
		cub_map->map.path_south_so[path++] = cub_map->map.map_two_d[i][j++];
	cub_map->map.path_south_so[path++] = '\0';
	cub_map->map.num_paths++;
	return (j);
}

void	check_south_path(t_all_struct *cub_map)
{
	int	i;
	int	j;

	i = 0;
	while (cub_map->map.map_two_d[i] && (i < cub_map->map.start_of_map))
	{
		j = 0;
		while (cub_map->map.map_two_d[i][j] == 32
			|| cub_map->map.map_two_d[i][j] == 9)
			j++;
		if (cub_map->map.map_two_d[i][j] == 'S' && cub_map->map.map_two_d[i][j + 1] == 'O'
            && (cub_map->map.map_two_d[i][j + 2] == 32
			|| cub_map->map.map_two_d[i][j + 2] == 9))
		{
			j = extract_south_path(cub_map, i, j);
			while (cub_map->map.map_two_d[i][j] == 32
				|| cub_map->map.map_two_d[i][j] == 9)
				j++;
			if (cub_map->map.map_two_d[i][j] != '\0')
				break ;
			return ;
		}
		i++;
	}
	free_all(cub_map, 1,
			"\033[1;31mMissed path:\033[0m there is no south path 😤\n");
}

int	extract_west_path(t_all_struct *cub_map, int i, int j)
{
	int	path;

	cub_map->map.index_west_line_we = j;
	j += 2;
	while (cub_map->map.map_two_d[i][j] == 32
		|| cub_map->map.map_two_d[i][j] == 9)
		j++;
	path = 0;
	while (cub_map->map.map_two_d[i][j] && cub_map->map.map_two_d[i][j] != 32
		&& cub_map->map.map_two_d[i][j] != 9)
		cub_map->map.path_west_we[path++] = cub_map->map.map_two_d[i][j++];
	cub_map->map.path_west_we[path++] = '\0';
	cub_map->map.num_paths++;
	return (j);
}

void	check_west_path(t_all_struct *cub_map)
{
	int	i;
	int	j;

	i = 0;
	while (cub_map->map.map_two_d[i] && (i < cub_map->map.start_of_map))
	{
		j = 0;
		while (cub_map->map.map_two_d[i][j] == 32
			|| cub_map->map.map_two_d[i][j] == 9)
			j++;
		if (cub_map->map.map_two_d[i][j] == 'W' && cub_map->map.map_two_d[i][j + 1] == 'E'
            && (cub_map->map.map_two_d[i][j + 2] == 32
			|| cub_map->map.map_two_d[i][j + 2] == 9))
		{
			j = extract_west_path(cub_map, i, j);
			while (cub_map->map.map_two_d[i][j] == 32
				|| cub_map->map.map_two_d[i][j] == 9)
				j++;
			if (cub_map->map.map_two_d[i][j] != '\0')
				break ;
			return ;
		}
		i++;
	}
	free_all(cub_map, 1,
			"\033[1;31mMissed path:\033[0m there is no west path 😤\n");
}

int	extract_east_path(t_all_struct *cub_map, int i, int j)
{
	int	path;

	cub_map->map.index_east_line_ea = j;
	j += 2;
	while (cub_map->map.map_two_d[i][j] == 32
		|| cub_map->map.map_two_d[i][j] == 9)
		j++;
	path = 0;
	while (cub_map->map.map_two_d[i][j] && cub_map->map.map_two_d[i][j] != 32
		&& cub_map->map.map_two_d[i][j] != 9)
		cub_map->map.path_east_ea[path++] = cub_map->map.map_two_d[i][j++];
	cub_map->map.path_east_ea[path++] = '\0';
	cub_map->map.num_paths++;
	return (j);
}

void	check_east_path(t_all_struct *cub_map)
{
	int	i;
	int	j;

	i = 0;
	while (cub_map->map.map_two_d[i] && (i < cub_map->map.start_of_map))
	{
		j = 0;
		while (cub_map->map.map_two_d[i][j] == 32
            || cub_map->map.map_two_d[i][j] == 9)
			j++;
		if (cub_map->map.map_two_d[i][j] == 'E' && cub_map->map.map_two_d[i][j + 1] == 'A'
            && (cub_map->map.map_two_d[i][j + 2] == 32
			|| cub_map->map.map_two_d[i][j + 2] == 9))
		{
			j = extract_east_path(cub_map, i, j);
			while (cub_map->map.map_two_d[i][j] == 32
				|| cub_map->map.map_two_d[i][j] == 9)
				j++;
			if (cub_map->map.map_two_d[i][j] != '\0')
				break ;
			return ;
		}
		i++;
	}
	free_all(cub_map, 1,
			"\033[1;31mMissed path:\033[0m there is no east path 😤\n");
}
