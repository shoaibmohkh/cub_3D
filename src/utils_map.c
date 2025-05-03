/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:03:02 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 22:55:07 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int count_row(t_map *cub_map, int start_pos)
{
    // 1111111
    // 1111111
    // 1111111 ==> 3 row
    int i;

    i = start_pos;
    while (cub_map->map_two_d[i])
        i++;
    return (i);
}

int count_col(t_map *cub_map, int start_pos)
{
    // 1234567
    // 1111111
    // 1111111 ==> 7 col
    int i;

    i = 0;
    while (cub_map->map_two_d[start_pos][i])
        i++;
    return (i);
}

int count_start_of_map(t_map *cub_map)
{
    int i;
    int j;

    i = 0;
    while (cub_map->map_two_d[i])
    {
        j = 0;
        while (cub_map->map_two_d[i][j] == 32)
            j++;
        if (cub_map->map_two_d[i][j] == '1')
            return (i);
        i++;
    }
}

int count_end_of_map(t_map *cub_map)
{
    int i;

    i = 0;
    while (cub_map->map_two_d[i])
        i++;
    return (i);
}
