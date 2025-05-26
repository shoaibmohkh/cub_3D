/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:06:15 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 20:18:21 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**split_rgb_tokens(char *s, char ***tokens)
{
	int	count;

	*tokens = ft_split(s, ',');
	if (!*tokens)
		return (NULL);
	count = 0;
	while ((*tokens)[count])
		count++;
	if (count != 3)
	{
		free_two_d(*tokens);
		return (NULL);
	}
	return (malloc(sizeof(char *) * 4));
}

char	**split_rgb(char *s)
{
	char	**tokens;
	char	**rgb;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	rgb = split_rgb_tokens(s, &tokens);
	if (!rgb)
		return (NULL);
	rgb[3] = NULL;
	while (i < 3)
	{
		rgb[i] = ft_strtrim(tokens[i], " \t");
		if (!rgb[i])
		{
			free_two_d(tokens);
			free_two_d(rgb);
			return (NULL);
		}
		i++;
	}
	free_two_d(tokens);
	return (rgb);
}

void	floor_color(t_all_struct *cub_map)
{
	char	*line;
	int		i;

	i = -1;
	while (cub_map->map.map_two_d[++i])
	{
		line = ft_strtrim(cub_map->map.map_two_d[i], " \t");
		if (!line)
			continue ;
		if (line[0] == 'F' && line[1] == ' ')
		{
			handle_color_line(cub_map, line, cub_map->map.floor_color);
			return ;
		}
		free(line);
	}
	free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
}

void	ceiling_color(t_all_struct *cub_map)
{
	char	*line;
	int		i;

	i = -1;
	while (cub_map->map.map_two_d[++i])
	{
		line = ft_strtrim(cub_map->map.map_two_d[i], " \t");
		if (!line)
			continue ;
		if (line[0] == 'C' && line[1] == ' ')
		{
			handle_color_line(cub_map, line, cub_map->map.ceiling_color);
			return ;
		}
		free(line);
	}
	free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
}
