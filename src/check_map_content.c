/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:59:01 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 23:07:28 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// return this checker
void check_chararcters(t_map *cub_map)
{
    int i;

    i = 0;
    if ((!(ft_strchr(cub_map->map_one_d, 'S')) && !(ft_strchr(cub_map->map_one_d, 'N')) 
        && !(ft_strchr(cub_map->map_one_d, 'E')) && !(ft_strchr(cub_map->map_one_d, 'W')))
        || !(ft_strchr(cub_map->map_one_d, '1')))
    {
        printf("\033[1;31mMissed characters:\033[0m in map file -N, S, E, W, 1- ❌\n");
        free_two_d(cub_map->map_two_d);
        free(cub_map->map_one_d);
        exit(1);
    }
    while (cub_map->map_one_d[i])
	{
		if (cub_map->map_one_d[i] == 'S' || cub_map->map_one_d[i] == 'N'
            || cub_map->map_one_d[i] == 'W' || cub_map->map_one_d[i] == 'E'
			|| cub_map->map_one_d[i] == '1' || cub_map->map_one_d[i] == '0'
            || cub_map->map_one_d[i] == '\n')
            i++;
        else
        {
            printf("\033[1;31mMissed characters:\033[0m in map file -0, 1, N, S, E, W- ❌\n");
            free_two_d(cub_map->map_two_d);
            free(cub_map->map_one_d);
            exit(1);
        }
	}
}

void wall_checker(t_map *cub_map, int pos)
{
    int j;

    j = 0;
    if (cub_map->map_two_d[pos]) // first line && last line
    {
        while (cub_map->map_two_d[pos][j] == 32) // skip space
            j++;
        while (cub_map->map_two_d[pos][j])
        {
            if (cub_map->map_two_d[pos][j] == '1')
                j++;
            else
            {
                printf("\033[1;31mMissed characters:\033[0m the first or last line not valid 😶‍🌫️\n");
                free_two_d(cub_map->map_two_d);
                free(cub_map->map_one_d);
                exit(1);
            }
        }
    }
}

void mid_wall_checker(t_map *cub_map, int start_of_map)
{
    int i;
    int pos;

    pos = start_of_map;
    while (cub_map->map_two_d[pos]) // first index
    {
        i = 0;
        while (cub_map->map_two_d[pos][i] == 32)
            i++;
        if (cub_map->map_two_d[pos][i] == '1')
            pos++;
        else
        {
            printf("\033[1;31mMissed characters:\033[0m the first index in row[%d] not valid 😶‍🌫️\n", pos);
            free_two_d(cub_map->map_two_d);
            free(cub_map->map_one_d);
            exit(1);
        }
    }
    while (cub_map->map_two_d[pos]) // last index
    {
        i = 0;
        while (cub_map->map_two_d[pos][i])
            i++;
        if (cub_map->map_two_d[pos][i - 1] == '1')
            pos++;
        else
        {
            printf("\033[1;31mMissed characters:\033[0m the first index in row[%d] not valid 😶‍🌫️\n", pos);
            free_two_d(cub_map->map_two_d);
            free(cub_map->map_one_d);
            exit(1);
        }
    }
}

void map_checker(t_map *cub_map)
{
    //RBG color
    floor_color(cub_map);
    ceiling_color(cub_map);
    //content of paths
    check_north_path(cub_map);
    check_south_path(cub_map);
    check_west_path(cub_map);
    check_east_path(cub_map);
    //shape of map
    check_chararcters(cub_map);
    wall_checker(cub_map, cub_map->start_of_map); // first line
    wall_checker(cub_map, cub_map->end_of_map); // last line
    mid_wall_checker(cub_map, cub_map->start_of_map); // midel rows check
}
