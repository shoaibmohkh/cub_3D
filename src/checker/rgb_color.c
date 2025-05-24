/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:06:15 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/22 22:02:12 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **split_rgb(char *s)
{
    char **tokens;
    char **rgb;
    int count;

    if (!s)
        return (NULL);
    tokens = ft_split(s, ',');
    if (!tokens)
        return (NULL);
    count = 0;
    while (tokens[count])
        count++;
    if (count != 3)
    {
        free_two_d(tokens);
        return (NULL);
    }
    rgb = malloc(sizeof(char *) * 4);
    if (!rgb)
    {
        free_two_d(tokens);
        return (NULL);
    }
    rgb[3] = NULL;
    for (int i = 0; i < 3; i++)
    {
        rgb[i] = ft_strtrim(tokens[i], " \t");
        if (!rgb[i])
        {
            free_two_d(tokens);
            free_two_d(rgb);
            return (NULL);
        }
    }

    free_two_d(tokens);
    return (rgb);
}


int is_valid_rgb(char **rgb)
{
    int i;
    int val;

    if (!rgb)
        return (0);
    i = 0;
    while (i < 3)
    {
        if (!rgb[i] || !*rgb[i])
            return (0);
        for (int j = 0; rgb[i][j]; j++)
        {
            if (!ft_isdigit(rgb[i][j]))
                return (0);
        }
        val = ft_atoi(rgb[i]);
        if (val < 0 || val > 255)
            return (0);
        i++;
    }
    return (1);
}

void floor_color(t_all_struct *cub_map)
{
    char *line;
    char **rgb;
    int i = -1;

    while (cub_map->map.map_two_d[++i])
    {
        line = ft_strtrim(cub_map->map.map_two_d[i], " \t");
        if (!line)
			continue;
        if (line[0] == 'F' && line[1] == ' ')
        {
            rgb = split_rgb(line + 2);
            free(line);
            
            if (!rgb || !is_valid_rgb(rgb))
            {
                free_two_d(rgb);
                free_all(cub_map, 1, "Invalid floor color format\n");
			}

            for (int j = 0; j < 3; j++)
                cub_map->map.floor_color[j] = ft_atoi(rgb[j]);
            free_two_d(rgb);
            return;
        }
        free(line);
    }
    free_all(cub_map, 1, "Missing floor color (F)\n");
}

void	ceiling_color(t_all_struct *cub_map)
{
    char *line;
    char **rgb;
    int i = -1;

    while (cub_map->map.map_two_d[++i])
    {
        line = ft_strtrim(cub_map->map.map_two_d[i], " \t");
        if (!line)
			continue;
        if (line[0] == 'C' && line[1] == ' ')
        {
            rgb = split_rgb(line + 2);
            free(line);
            if (!rgb || !is_valid_rgb(rgb))
            {
                free_two_d(rgb);
                free_all(cub_map, 1, "Invalid ceil color format\n");
            }
            for (int j = 0; j < 3; j++)
                cub_map->map.ceiling_color[j] = ft_atoi(rgb[j]);
            free_two_d(rgb);
            return;
        }
        free(line);
    }
    free_all(cub_map, 1, "Missing floor color (C)\n");
}

