/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:49:30 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 22:53:08 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_north_path(t_map *cub_map)
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

void check_south_path(t_map *cub_map)
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
        if (cub_map->map_two_d[i][j] == 'S' && cub_map->map_two_d[i][j + 1] == 'O')
        {
            cub_map->index_south_line_so = j;
            j += 2;
            while (cub_map->map_two_d[i][j] == 32 || cub_map->map_two_d[i][j] == 9)
                j++;
            while (cub_map->map_two_d[i][j])
                cub_map->path_south_so[path++] = cub_map->map_two_d[i][j++];
            return ;
        }
        i++;
    }
    printf("\033[1;31mMissed path:\033[0m there is no south path 😤\n");
    free_two_d(cub_map->map_two_d);
    free(cub_map->map_one_d);
    exit(1);
}

void check_west_path(t_map *cub_map)
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
        if (cub_map->map_two_d[i][j] == 'W' && cub_map->map_two_d[i][j + 1] == 'E')
        {
            cub_map->index_west_line_we = j;
            j += 2;
            while (cub_map->map_two_d[i][j] == 32 || cub_map->map_two_d[i][j] == 9)
                j++;
            while (cub_map->map_two_d[i][j])
                cub_map->path_west_we[path++] = cub_map->map_two_d[i][j++];
            return ;
        }
        i++;
    }
    printf("\033[1;31mMissed path:\033[0m there is no west path 😤\n");
    free_two_d(cub_map->map_two_d);
    free(cub_map->map_one_d);
    exit(1);
}

void check_east_path(t_map *cub_map)
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
            cub_map->index_east_line_ea = j;
            j += 2;
            while (cub_map->map_two_d[i][j] == 32 || cub_map->map_two_d[i][j] == 9)
                j++;
            while (cub_map->map_two_d[i][j])
                cub_map->path_east_ea[path++] = cub_map->map_two_d[i][j++];
            return ;
        }
        i++;
    }
    printf("\033[1;31mMissed path:\033[0m there is no east path 😤\n");
    free_two_d(cub_map->map_two_d);
    free(cub_map->map_one_d);
    exit(1);
}
