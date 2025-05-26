/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:59:01 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 15:29:52 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_wall_start_indices(t_all_struct *cub_map)
{
	int	i;
	int	pos;

	pos = 0;
	while (cub_map->map.real_map_two_d[pos])
	{
		i = 0;
		while (cub_map->map.real_map_two_d[pos][i] == 32
			|| cub_map->map.real_map_two_d[pos][i] == 9)
			i++;
		if (cub_map->map.real_map_two_d[pos][i] == '\0')
		{
			pos++;
			continue ;
		}
		if (cub_map->map.real_map_two_d[pos][i] == '1'
			|| cub_map->map.real_map_two_d[pos][i] == 32
			|| cub_map->map.real_map_two_d[pos][i] == '\t')
			pos++;
		else
			free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
	}
}

void	check_wall_end_indices(t_all_struct *cub_map)
{
	int	i;
	int	pos;

	pos = 0;
	while (cub_map->map.real_map_two_d[pos])
	{
		i = 0;
		while (cub_map->map.real_map_two_d[pos][i])
			i++;
		if (cub_map->map.real_map_two_d[pos][i - 1] == '1'
			|| cub_map->map.real_map_two_d[pos][i - 1] == 32
			|| cub_map->map.real_map_two_d[pos][i - 1] == 9)
			pos++;
		else
			free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
	}
}

void	mid_wall_checker(t_all_struct *cub_map)
{
	check_wall_start_indices(cub_map);
	check_wall_end_indices(cub_map);
}

void	check_befor_real_map(t_all_struct *cub_map)
{
	if (cub_map->map.start_of_map != 6)
		free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
}

void	last_wall_checker(t_all_struct *cub_map)
{
	int	i;
	int	end;

	i = 0;
	while (cub_map->map.real_map_two_d[i])
		i++;
	end = i - 1;
	i = 0;
	while (cub_map->map.real_map_two_d[end][i])
	{
		if (cub_map->map.real_map_two_d[end][i] == '1'
			|| cub_map->map.real_map_two_d[end][i] == 32
			|| cub_map->map.real_map_two_d[end][i] == 9)
			i++;
		else
			free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
	}
}
