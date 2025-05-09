/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:06:15 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/09 03:23:02 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **split_rgb(char *s)
{
    char **rgb;
    char *dup;
    char *tok;
    int i;

    if (!s || !*s)
        return NULL;
    dup = ft_strdup(s);
    if (!dup)
        return NULL;

    rgb = malloc(sizeof(char *) * 4);
    if (!rgb)
        return (free(dup), NULL);
    for (int k = 0; k < 4; k++)
        rgb[k] = NULL;

    i = 0;
    tok = strtok(dup, ",");
    while (tok && i < 3)
    {
        rgb[i] = ft_strtrim(tok, " \t");
        if (!rgb[i])
        {
            free(dup);
            free_two_d(rgb);
            return NULL;
        }
        i++;
        tok = strtok(NULL, ",");
    }
    free(dup);
    if (i != 3 || tok != NULL)
    {
        free_two_d(rgb);
        return NULL;
    }

    rgb[3] = NULL;
    return rgb;
}


int	is_valid_rgb(char **rgb)
{
	char	*endp;
	long	v;
	int		i;

	i = 0;
	while (i < 3)
	{
		if (!rgb[i] || !*rgb[i])
			return (0);
		v = strtol(rgb[i], &endp, 10);
		if (*endp || v < 0 || v > 255)
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
                printf("Invalid floor color format");
				exit (1);
			}

            for (int j = 0; j < 3; j++)
                cub_map->map.floor_color[j] = atoi(rgb[j]);
            
            free_two_d(rgb);
            return;
        }
        free(line);
    }
    printf("Missing floor color (F)");
	exit (1);
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
                printf("Invalid ceil color format");
				exit (1);
			}

            for (int j = 0; j < 3; j++)
                cub_map->map.ceiling_color[j] = atoi(rgb[j]);
            
            free_two_d(rgb);
            return;
        }
        free(line);
    }
    printf("Missing floor color (C)");
	exit (1);
}

