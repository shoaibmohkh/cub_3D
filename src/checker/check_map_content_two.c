/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:29:29 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 15:30:01 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
				free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
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
		free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
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
			free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
		i++;
	}
	return (count_player);
}

void	check_chararcters(t_all_struct *cub_map)
{
	check_empty_lines(cub_map);
	check_required_elements(cub_map);
	if (validate_and_count_players(cub_map) != 1)
		free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
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
			free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
	}
}
