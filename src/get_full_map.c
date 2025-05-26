/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:58:21 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 19:13:19 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*read_and_join_lines(int fd, char *str)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		str = process_line(line, str, fd);
		line = get_next_line(fd);
	}
	return (str);
}

char	*reading_file(int fd)
{
	char	*str;

	str = ft_strdup("");
	if (!str)
	{
		close(fd);
		printf("\033[1;31fail: in -strdup-\033[0m 📛\n");
		exit(1);
	}
	str = read_and_join_lines(fd, str);
	close(fd);
	if (ft_strlen(str) == 0 || !str)
	{
		printf("\033[1;31mfail: in -join-\033[0m 📛\n");
		free(str);
		exit(1);
	}
	return (str);
}

void	get_and_copies_map(t_all_struct *cub_map, int fd)
{
	cub_map->map.map_one_d = reading_file(fd);
	if (!cub_map->map.map_one_d)
		free_all(cub_map, 1,
			"\033[1;31merror in reading map\033[0m 📛\n");
	cub_map->map.map_two_d = ft_split(cub_map->map.map_one_d, '\n');
	if (!cub_map->map.map_two_d)
		free_all(cub_map, 1,
			"\033[1;31mfail: in -split-\033[0m 📛\n");
	cub_map->map.start_of_map = count_start_of_map(cub_map);
	if (cub_map->map.start_of_map == -1)
		free_all(cub_map, 1,
			"\033[1;31mfail: can't find the map\033[0m 📛\n");
	cub_map->map.end_of_map = count_end_of_map(cub_map);
	cub_map->map.real_map_two_d = get_real_map_two_d(cub_map);
	if (!cub_map->map.real_map_two_d)
		free_all(cub_map, 1,
			"\033[1;31mfail: can't copy the map\033[0m 📛\n");
	cub_map->map.real_map_one_d = get_real_map_one_d(cub_map);
	if (!cub_map->map.real_map_one_d)
		free_all(cub_map, 1,
			"\033[1;31mfail: can't copy the map\033[0m 📛\n");
}

void	get_map(t_all_struct *cub_map, int fd)
{
	get_and_copies_map(cub_map, fd);
	cub_map->map.col = count_col(cub_map);
	cub_map->map.row = count_row(cub_map);
}
