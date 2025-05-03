/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:06:15 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 23:12:59 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void floor_color(t_map *cub_map)
{
    int i;
    int j;
    int p;
    char num[3];

    p = 0;
    j = 0;
    i = 0;
    while (cub_map->map_two_d[i])
    {
        while (cub_map->map_two_d[i][j] == 32)
            j++;
        if (cub_map->map_two_d[i][j] == 'F')
        {
            cub_map->index_north_line_no = j;
            j++;
            while (cub_map->map_two_d[i][j] == 32 || cub_map->map_two_d[i][j] == 9)
                j++;
            while (cub_map->map_two_d[i][j] != 32 && cub_map->map_two_d[i][j] != ',')
                num[p++] = cub_map->map_two_d[i][j++];
            
            return ;
        }
        i++;
    }
    printf("\033[1;31mMissed path:\033[0m there is no north path 😤\n");
    free_two_d(cub_map->map_two_d);
    free(cub_map->map_one_d);
    exit(1);
}

void ceiling_color(t_map *cub_map)
{
    int i;
    int j;
    int path;

    path = 0;
    j = 0;
    i = 0;
    while (cub_map->map_two_d[i])
    {
        while (cub_map->map_two_d[i][j] == 32)
            j++;
        if (cub_map->map_two_d[i][j] == 'N' && cub_map->map_two_d[i][j + 1] == 'O')
        {
            cub_map->index_north_line_no = j;
            j += 2;
            while (cub_map->map_two_d[i][j] == 32 || cub_map->map_two_d[i][j] == 9)
                j++;
            while (cub_map->map_two_d[i][j])
                cub_map->path_north_no[path++] = cub_map->map_two_d[i][j++];
            return ;
        }
        i++;
    }
    printf("\033[1;31mMissed path:\033[0m there is no north path 😤\n");
    free_two_d(cub_map->map_two_d);
    free(cub_map->map_one_d);
    exit(1);
}