/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:09:27 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/20 14:03:51 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_struct(t_all_struct *cub_map)
{
	int	i;

	i = 0;
	printf("------ map_one_d ------\n%s\n", cub_map->map.map_one_d);
	printf("------ map_two_d ------\n");
	for (int i = 0; cub_map->map.map_two_d[i]; i++)
		printf("[%d]: %s\n", i, cub_map->map.map_two_d[i]);
	printf("------ start_of_map ------\n%d\n", cub_map->map.start_of_map);
	printf("------ end_of_map ------\n%d\n", cub_map->map.end_of_map);
	printf("------ real_map_two_d ------\n");
	for (int i = 0; cub_map->map.real_map_two_d[i]; i++)
		printf("[%d]: %s\n", i, cub_map->map.real_map_two_d[i]);
	printf("------ real_map_one_d ------\n%s\n", cub_map->map.real_map_one_d);
	printf("------ cout_col ------\n%d\n", cub_map->map.col);
	printf("------ count_row ------\n%d\n", cub_map->map.row);
    printf("------ floor_color ------\n");
    for (i = 0; i < 3; i++)
	{
        printf("%d\n", cub_map->map.floor_color[i]);
	}
	printf("------ ceiling_color ------\n");
    for (i = 0; i < 3; i++)
	{
        printf("%d\n", cub_map->map.ceiling_color[i]);
	}
	printf("------ paths------\n");
	printf("no path: %s\n", cub_map->map.path_north_no);
	printf("so path: %s\n", cub_map->map.path_south_so);
	printf("we path: %s\n", cub_map->map.path_west_we);
	printf("ea path: %s\n", cub_map->map.path_east_ea);
}
