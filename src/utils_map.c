/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:03:02 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/06 20:57:18 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int count_row(t_all_struct *cub_map)
{
    // 1111111
    // 1111111
    // 1111111 ==> 3 row
    int i;

    i = 0;
    while (cub_map->map.real_map_two_d[i])
        i++;
    return (i);
}

int count_col(t_all_struct *cub_map)
{
    // 1234567
    // 1111111
    // 1111111 ==> 7 col
    int max_col;
	int current_col;
	int i;

	max_col = 0;
	i = 0;
	while (cub_map->map.real_map_two_d[i])
	{
		current_col = ft_strlen(cub_map->map.real_map_two_d[i]);
		if (current_col > max_col)
			max_col = current_col;
		i++;
	}
	return (max_col);
}

int count_start_of_map(t_all_struct *cub_map)
{
    int i;
    int j;

    i = 0;
    while (cub_map->map.map_two_d[i])
    {
        j = 0;
        while (cub_map->map.map_two_d[i][j] == 32 || cub_map->map.map_two_d[i][j] == 9)
            j++;
        if (cub_map->map.map_two_d[i][j] == '1' || cub_map->map.map_two_d[i][j] == '0'
            || (cub_map->map.map_two_d[i][j] == 'N' && cub_map->map.map_two_d[i][j + 1] != 'O')
            || (cub_map->map.map_two_d[i][j] == 'S' && cub_map->map.map_two_d[i][j + 1] != 'O')
            || (cub_map->map.map_two_d[i][j] == 'W' && cub_map->map.map_two_d[i][j + 1] != 'E')
            || (cub_map->map.map_two_d[i][j] == 'E' && cub_map->map.map_two_d[i][j + 1] != 'A'))
            return (i);
        i++;
    }
    return (-1);
}

int count_end_of_map(t_all_struct *cub_map)
{
    int i;

    i = 0;
    while (cub_map->map.map_two_d[i])
        i++;
    return (i);
}
