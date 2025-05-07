/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:59:01 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/07 23:35:24 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <ctype.h>

// return this checker
void    check_chararcters(t_all_struct *cub_map)
{
    int i;
    int count_player = 0;
    int end = cub_map->map.end_of_map;

    i = cub_map->map.start_of_map;
    // تحقق فقط ضمن حدود الخريطة
    while (i <= end)
    {
        if (cub_map->map.map_one_d[i] == '\n')
        {
            int j = i + 1;
            // تخطي المسافات والتاب ضمن حدود الخريطة
            while (j <= end && (cub_map->map.map_one_d[j] == ' ' || cub_map->map.map_one_d[j] == '\t'))
                j++;
            // إذا وجدنا سطر جديد فهناك سطر فارغ داخل الخريطة
            if (j <= end && cub_map->map.map_one_d[j] == '\n')
            {
                printf("\033[1;31mMissed characters:\033[0m there is new line in the map ❌\n");
                free_two_d(cub_map->map.map_two_d);
                free(cub_map->map.map_one_d);
                exit(1);
            }
        }
        i++;
    }

    // تحقق من وجود جدار واحد على الأقل واتجاه لاعب واحد على الأقل
    if ((!ft_strchr(cub_map->map.real_map_one_d, '1')) ||
        (!ft_strchr(cub_map->map.real_map_one_d, 'N') && !ft_strchr(cub_map->map.real_map_one_d, 'S') &&
         !ft_strchr(cub_map->map.real_map_one_d, 'E') && !ft_strchr(cub_map->map.real_map_one_d, 'W')))
    {
        printf("\033[1;31mMissed characters:\033[0m in map file1 -N, S, E, W, 1- ❌\n");
        free_two_d(cub_map->map.map_two_d);
        free(cub_map->map.map_one_d);
        exit(1);
    }

    // التحقق من الأحرف الصحيحة وعدد اللاعبين
    i = 0;
    while (cub_map->map.real_map_one_d[i])
    {
        char c = cub_map->map.real_map_one_d[i];
        if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
            count_player++;
        else if (c != '0' && c != '1' && c != '\n' && c != ' ' && c != '\t')
        {
            printf("\033[1;31mMissed characters:\033[0m in map file2 -0, 1, N, S, E, W- ❌\n");
            free_two_d(cub_map->map.map_two_d);
            free(cub_map->map.map_one_d);
            exit(1);
        }
        i++;
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
    int j = 0;
    while (cub_map->map.map_two_d[pos][j] == ' ' || cub_map->map.map_two_d[pos][j] == '\t')
        j++;
    while (cub_map->map.map_two_d[pos][j])
    {
        if (cub_map->map.map_two_d[pos][j] == '1' || 
            cub_map->map.map_two_d[pos][j] == ' ' || 
            cub_map->map.map_two_d[pos][j] == '\t')
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
            || (cub_map->map.map_two_d[i][j] == 'E' && cub_map->map.map_two_d[i][j + 1] == 'A')
            || (cub_map->map.map_two_d[i][j] == 'C' && cub_map->map.map_two_d[i][j + 1] == ' ')
            || (cub_map->map.map_two_d[i][j] == 'F' && cub_map->map.map_two_d[i][j + 1] == ' ')))
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
    int i = 0;
    //RBG color
    floor_color(cub_map);
    printf("------ floor_color------\n");
    while (cub_map->map.floor_color[i])
    {
        printf("%i\n", cub_map->map.floor_color[i]);
        i++;
    }
    ceiling_color(cub_map);
    printf("------ ceiling_color------\n");
    i = 0;
    while (cub_map->map.ceiling_color[i])
    {
        printf("%i\n", cub_map->map.ceiling_color[i]);
        i++;
    }
    //content of paths
    check_north_path(cub_map);
    printf("no path: %s\n",cub_map->map.path_north_no);
    check_south_path(cub_map);
    printf("so path: %s\n",cub_map->map.path_south_so);
    check_west_path(cub_map);
    printf("we path: %s\n",cub_map->map.path_west_we);
    check_east_path(cub_map);
    printf("ea path: %s\n",cub_map->map.path_east_ea);
    check_befor_real_map(cub_map);
    //shape of map
    check_chararcters(cub_map);
    wall_checker(cub_map, cub_map->map.start_of_map); // first line
    printf("ok1\n");
    wall_checker(cub_map, cub_map->map.end_of_map - 1); // last line
    printf("ok2\n");
    // mid_wall_checker(cub_map, cub_map->map.start_of_map); // midel rows check
    // if (!check_map_validity(cub_map))
    // {
    //     free_all(cub_map, 1
    //         ,"not a valid map");
    // }
}
