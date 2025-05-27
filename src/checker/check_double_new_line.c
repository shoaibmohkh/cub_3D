/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_new_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:36:54 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 17:56:08 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_lines_array(char **lines, char *str, size_t count)
{
	char	*ptr;
	char	*line_start;
	size_t	i;

	ptr = str;
	i = 0;
	while (i < count && *ptr)
	{
		line_start = ptr;
		while (*ptr && *ptr != '\n')
			ptr++;
		lines[i] = ft_substr(line_start, 0, ptr - line_start);
		if (!lines[i])
		{
			free_lines_on_error(lines, i);
			return (0);
		}
		i++;
		if (*ptr == '\n')
			ptr++;
	}
	return (1);
}

int	fill_remaining_empty_lines(char **lines, size_t i, size_t count)
{
	while (i < count)
	{
		lines[i] = ft_strdup("");
		if (!lines[i])
		{
			free_two_d(lines);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**splitt(char *str)
{
	char	**lines;
	size_t	count;

	if (!str)
		return (NULL);
	count = count_lines(str);
	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (NULL);
	if (!fill_lines_array(lines, str, count))
		return (NULL);
	if (!fill_remaining_empty_lines(lines, count_lines(str), count))
		return (NULL);
	lines[count] = NULL;
	return (lines);
}

int	check_d_new_line(char **map_t, int start, int end)
{
	int	i;

	if (!map_t)
		return (1);
	i = start;
	while (i <= end)
	{
		if (!map_t[i])
			return (1);
		if (ft_strlen(map_t[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	check_new_lines(t_all_struct *cub_map)
{
	char	**map_two_dd;
	int		i;
	int		end;

	map_two_dd = splitt(cub_map->map.map_one_d);
	if (!map_two_dd)
		free_all(cub_map, 1, "\033[1;31mfail: in -split-\033[0m 📛\n");
	i = count_start_of_tmap(map_two_dd);
	end = count_end_of_tmap(map_two_dd);
	if (i == -1 || end == -1)
	{
		free_two_d(map_two_dd);
		free_all(cub_map, 1, "\033[1;31merror in map\033[0m 😤\n");
	}
	if (check_d_new_line(map_two_dd, i, end))
	{
		free_two_d(map_two_dd);
		free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
	}
	free_two_d(map_two_dd);
}
