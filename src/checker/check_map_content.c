/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:59:01 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/20 14:16:59 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// return this function
void	check_empty_lines(t_all_struct *cub_map)
{
	int	i;
	int	j;

	i = cub_map->map.start_of_map;
	while (i <= cub_map->map.end_of_map)
	{
		if (cub_map->map.map_one_d[i] == '\n')
		{
			j = i + 1;
			while (j <= cub_map->map.end_of_map
				&& (cub_map->map.map_one_d[j] == ' '
					|| cub_map->map.map_one_d[j] == '\t'))
				j++;
			if (j <= cub_map->map.end_of_map
				&& cub_map->map.map_one_d[j] == '\n')
				free_all(cub_map, 1,
				    "\033[1;31mthere is new line in the map\033[0m ❌\n");
		}
		i++;
	}
}

void	check_required_elements(t_all_struct *cub_map)
{
	if ((!ft_strchr(cub_map->map.real_map_one_d, '1'))
		|| (!ft_strchr(cub_map->map.real_map_one_d, 'N')
			&& !ft_strchr(cub_map->map.real_map_one_d, 'S')
			&& !ft_strchr(cub_map->map.real_map_one_d, 'E')
			&& !ft_strchr(cub_map->map.real_map_one_d, 'W')))
		free_all(cub_map, 1,
            "\033[1;31min map file1 -N, S, E, W, 1-\033[0m ❌\n");
}

int	validate_and_count_players(t_all_struct *cub_map)
{
	int		i;
	int		count_player;
	char	c;

	count_player = 0;
	i = 0;
	while (cub_map->map.real_map_one_d[i])
	{
		c = cub_map->map.real_map_one_d[i];
		if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
			count_player++;
		else if (c != '0' && c != '1' && c != '\n' && c != ' ' && c != '\t')
			free_all(cub_map, 1, "\033[1;31min map file2 -0, 1, N, S, E, W-\033[0m ❌\n");
		i++;
	}
	return (count_player);
}

void	check_chararcters(t_all_struct *cub_map)
{
	check_empty_lines(cub_map);
	check_required_elements(cub_map);
	if (validate_and_count_players(cub_map) != 1)
		free_all(cub_map, 1,
				"\033[1;31mthere is error in number of player\033[0m ❌\n");
}

void	wall_checker(t_all_struct *cub_map, int pos)
{
	int	j;

	j = 0;
	while (cub_map->map.map_two_d[pos][j] == ' '
		|| cub_map->map.map_two_d[pos][j] == '\t')
		j++;
	while (cub_map->map.map_two_d[pos][j])
	{
		if (cub_map->map.map_two_d[pos][j] == '1' ||
			cub_map->map.map_two_d[pos][j] == ' ' ||
			cub_map->map.map_two_d[pos][j] == '\t')
			j++;
		else
			free_all(cub_map, 1,
					"\033[1;31mthe first or last line not valid\033[0m 😶‍🌫️\n");
	}
}

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
			free_all(cub_map, 1,
					"\033[1;31mthe first index not valid\033[0m 😶‍🌫️\n");
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
			free_all(cub_map, 1,
					"\033[1;31mthe last index not valid\033[0m 😶‍🌫️\n");
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
		free_all(cub_map, 1,
				"\033[1;31mnumber of paths not okay\033[0m 😶‍🌫️\n");
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
			free_all(cub_map, 1, "\033[1;31mlast line in the map have error\033[0m 😶‍🌫️\n");
	}
}
