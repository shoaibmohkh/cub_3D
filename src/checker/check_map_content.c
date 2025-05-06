/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:59:01 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/06 21:05:07 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// return this checker
void check_chararcters(t_all_struct *cub_map)
{
    int i;
    int count_player = 0;

    i = 0;
    while (cub_map->map.real_map_one_d[i])
    {
        if (cub_map->map.real_map_one_d[i] == '\n')
        {
            i++;
            while (cub_map->map.real_map_one_d[i] == 32 || cub_map->map.real_map_one_d[i] == 9)
                i++;
            if (cub_map->map.real_map_one_d[i] == '\n')
            {
                printf("\033[1;31mMissed characters:\033[0m there is new line in the map ❌\n");
                free_two_d(cub_map->map.map_two_d);
                free(cub_map->map.map_one_d);
                exit(1);
            }
        }
        i++;
    }
    if ((!(ft_strchr(cub_map->map.real_map_one_d, 'S')) && !(ft_strchr(cub_map->map.real_map_one_d, 'N')) 
        && !(ft_strchr(cub_map->map.real_map_one_d, 'E')) && !(ft_strchr(cub_map->map.real_map_one_d, 'W')))
        || !(ft_strchr(cub_map->map.real_map_one_d, '1')))
    {
        printf("\033[1;31mMissed characters:\033[0m in map file -N, S, E, W, 1- ❌\n");
        free_two_d(cub_map->map.map_two_d);
        free(cub_map->map.map_one_d);
        exit(1);
    }
    i = 0;
    while (cub_map->map.real_map_one_d[i])
	{
		if (cub_map->map.real_map_one_d[i] == 'S' || cub_map->map.real_map_one_d[i] == 'N'
            ||  cub_map->map.real_map_one_d[i] == 'W' || cub_map->map.real_map_one_d[i] == 'E'
			|| cub_map->map.real_map_one_d[i] == '1' || cub_map->map.real_map_one_d[i] == '0'
            || cub_map->map.real_map_one_d[i] == '\n')
        {
            i++;
            if (cub_map->map.real_map_one_d[i] == 'S' || cub_map->map.real_map_one_d[i] == 'N'
                ||  cub_map->map.real_map_one_d[i] == 'W' || cub_map->map.real_map_one_d[i] == 'E')
                count_player++;
        }
        else
        {
            printf("\033[1;31mMissed characters:\033[0m in map file -0, 1, N, S, E, W- ❌\n");
            free_two_d(cub_map->map.map_two_d);
            free(cub_map->map.map_one_d);
            exit(1);
        }
	}
    if (count_player != 1)
    {
        printf("\033[1;31mMissed characters:\033[0m there is error in number of player ❌\n");
        free_two_d(cub_map->map.map_two_d);
        free(cub_map->map.map_one_d);
        exit(1);
    }
}

void wall_checker(t_all_struct *cub_map, int pos)
{
    int j;

    j = 0;
    if (cub_map->map.map_two_d[pos]) // first line && last line
    {
        while (cub_map->map.map_two_d[pos][j] == 32) // skip space
            j++;
        while (cub_map->map.map_two_d[pos][j])
        {
            if (cub_map->map.map_two_d[pos][j] == '1' || cub_map->map.map_two_d[pos][j] == 32)
                j++;
            else
            {
                printf("\033[1;31mMissed characters:\033[0m the first or last line not valid 😶‍🌫️\n");
                free_two_d(cub_map->map.map_two_d);
                free(cub_map->map.map_one_d);
                exit(1);
            }
        }
    }
}

// void mid_wall_checker(t_all_struct *cub_map, int start_of_map)
// {
//     int i;
//     int pos;

//     pos = start_of_map;
//     while (cub_map->map.map_two_d[pos]) // first index
//     {
//         i = 0;
//         while (cub_map->map.map_two_d[pos][i] == 32)
//             i++;
//         if (cub_map->map.map_two_d[pos][i] == '1')
//             pos++;
//         else
//         {
//             printf("\033[1;31mMissed characters:\033[0m the first index in row[%d] not valid 😶‍🌫️\n", pos);
//             free_two_d(cub_map->map.map_two_d);
//             free(cub_map->map.map_one_d);
//             exit(1);
//         }
//     }
//     while (cub_map->map.map_two_d[pos]) // last index
//     {
//         i = 0;
//         while (cub_map->map.map_two_d[pos][i])
//             i++;
//         if (cub_map->map.map_two_d[pos][i - 1] == '1')
//             pos++;
//         else
//         {
//             printf("\033[1;31mMissed characters:\033[0m the first index in row[%d] not valid 😶‍🌫️\n", pos);
//             free_two_d(cub_map->map.map_two_d);
//             free(cub_map->map.map_one_d);
//             exit(1);
//         }
//     }
// }

void check_befor_real_map(t_all_struct *cub_map)
{
    int i = 0;
    int j = 0;
    int f = 0;
    while (i < cub_map->map.start_of_map)
    {
        while (cub_map->map.map_two_d[i][j] == 32 || cub_map->map.map_two_d[i][j] == 9)
            j++;
        if (cub_map->map.map_two_d[i][j] 
            && ((cub_map->map.map_two_d[i][j] == 'N' && cub_map->map.map_two_d[i][j + 1] == 'O')
            || (cub_map->map.map_two_d[i][j] == 'S' && cub_map->map.map_two_d[i][j + 1] == 'O')
            || (cub_map->map.map_two_d[i][j] == 'W' && cub_map->map.map_two_d[i][j + 1] == 'E')
            || (cub_map->map.map_two_d[i][j] == 'E' && cub_map->map.map_two_d[i][j + 1] == 'A')))
        {
            f++;
        }
        i++;
    }
    if (f > 6)
        free_all(cub_map, 1
            ,"number of paths not okay");
}

void map_checker(t_all_struct *cub_map)
{
    //RBG color
    floor_color(cub_map);
    ceiling_color(cub_map);
    //content of paths
    check_north_path(cub_map);
    check_south_path(cub_map);
    check_west_path(cub_map);
    check_east_path(cub_map);
    if (cub_map->map.num_paths != 4)
        free_all(cub_map, 1
            ,"number of paths not okay");
    //shape of map
    check_chararcters(cub_map);
    check_befor_real_map(cub_map);
    wall_checker(cub_map, cub_map->map.start_of_map); // first line
    wall_checker(cub_map, cub_map->map.end_of_map); // last line
    // mid_wall_checker(cub_map, cub_map->map.start_of_map); // midel rows check
    // if (!check_map_validity(cub_map))
    // {
    //     free_all(cub_map, 1
    //         ,"not a valid map");
    // }
}
