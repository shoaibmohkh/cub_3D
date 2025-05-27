/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_new_line2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:36:54 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 18:04:08 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N' && *line != 'S'
			&& *line != 'E' && *line != 'W'
			&& !ft_isspace((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}

int	count_end_of_tmap(char **map_two_d)
{
	int		i;
	int		last_non_empty;
	char	*str;

	i = 0;
	last_non_empty = -1;
	while (map_two_d[i])
	{
		str = ft_strtrim(map_two_d[i], " \t");
		if (!str)
			return (-1);
		if (str[0] != '\0' && is_map_line(str))
			last_non_empty = i;
		free(str);
		i++;
	}
	return (last_non_empty);
}

static int	is_config_line(char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0 || ft_strncmp(str, "SO", 2) == 0
		|| ft_strncmp(str, "WE", 2) == 0 || ft_strncmp(str, "EA", 2) == 0
		|| str[0] == 'F' || str[0] == 'C')
		return (1);
	return (0);
}

int	count_start_of_tmap(char **map_two_d)
{
	int		i;
	char	*str;

	i = 0;
	while (map_two_d[i])
	{
		str = ft_strtrim(map_two_d[i], " \t");
		if (!str)
			return (-1);
		if (str[0] == '\0' || is_config_line(str))
		{
			free(str);
			i++;
			continue ;
		}
		free(str);
		return (i);
	}
	return (-1);
}

int	count_lines(char *str)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = str;
	while (*ptr)
	{
		if (*ptr == '\n')
			count++;
		ptr++;
	}
	if (*(ptr - 1) != '\n')
		count++;
	return (count);
}
