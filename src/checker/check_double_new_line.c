/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_new_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:36:54 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/27 14:58:12 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_map_line(const char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N' &&
			*line != 'S' && *line != 'E' && *line != 'W' &&
			!ft_isspace((unsigned char)*line))
			return 0;
		line++;
	}
	return 1;
}

int	count_end_of_tmap(char **map_two_d)
{
	int i = 0;
	int last_non_empty = -1;

	while (map_two_d[i])
	{
		char *trimmed = ft_strtrim(map_two_d[i], " \t");
		if (!trimmed)
			return (-1);
		if (trimmed[0] != '\0' && is_map_line(trimmed))
			last_non_empty = i;
		free(trimmed);
		i++;
	}
	return (last_non_empty);
}

int	count_start_of_tmap(char **map_two_d)
{
	int		i = 0;
	char	*trimmed;

	while (map_two_d[i])
	{
		trimmed = ft_strtrim(map_two_d[i], " \t");
		if (!trimmed)
			return (-1);
		
		if (trimmed[0] == '\0')
		{
			free(trimmed);
			i++;
			continue;
		}
		if (ft_strncmp(trimmed, "NO", 2) == 0 ||
			ft_strncmp(trimmed, "SO", 2) == 0 ||
			ft_strncmp(trimmed, "WE", 2) == 0 ||
			ft_strncmp(trimmed, "EA", 2) == 0 ||
			trimmed[0] == 'F' || trimmed[0] == 'C')
		{
			free(trimmed);
			i++;
			continue;
		}
		free(trimmed);
		return (i);
	}
	return (-1);
}

char **splitt(char *str)
{
    char	**lines;
    size_t	count = 0;
    char	*ptr = str;
    char	*line_start;
	
    while (*ptr)
    {
        if (*ptr == '\n')
            count++;
        ptr++;
    }
    if (*(ptr - 1) != '\n')
        count++;
    lines = malloc(sizeof(char *) * (count + 1));
    if (!lines)
        return (NULL);

    ptr = str;
    size_t i = 0;
    while (i < count && *ptr)
    {
        line_start = ptr;
        while (*ptr && *ptr != '\n')
            ptr++;
        lines[i++] = ft_substr(line_start, 0, ptr - line_start);
        if (*ptr == '\n')
            ptr++;
    }
    while (i < count)
        lines[i++] = ft_strdup("");

    lines[i] = NULL;
    return (lines);
}

int check_d_new_line(char **map_t, int start, int end)
{
    int i = start;
	while ( i <= end)
	{
		if (ft_strlen(map_t[i]) == 0)
			return 1;
        i++;
	}
	return 0;
}

void check_new_lines(t_all_struct *cub_map)
{
	char **map_two_dd = splitt(cub_map->map.map_one_d);
	int i = count_start_of_tmap(map_two_dd);
	int end = count_end_of_tmap(map_two_dd);
	if (!map_two_dd)
		free_all(cub_map, 1,
			"\033[1;31mfail: in -split-\033[0m 📛\n");
	if (check_d_new_line(map_two_dd, i, end))
	{
		free_two_d(map_two_dd);
		free_all(cub_map, 1, "error new line");
	}
}
