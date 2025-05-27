/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:14:44 by zsalah            #+#    #+#             */
/*   Updated: 2025/05/27 15:37:18 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_walkable(char c)
{
	return (c == '0' || c == ' ' || ft_is_player(c));
}

int	find_player(char **map, t_all_struct *cub, t_point *player)
{
	int	y;
	int	total_count;

	y = 0;
	total_count = 0;
	while (y < cub->map.row)
	{
		total_count += scan_row_for_player(map[y], y, cub, player);
		y++;
	}
	return (total_count == 1);
}

int	flood_fill(t_fill_data *data)
{
	t_point	curr;
	int		i;
	int		nx;
	int		ny;

	while (*(data->front) < *(data->back))
	{
		curr = data->array[(*(data->front))++];
		i = 0;
		while (i < 4)
		{
			nx = curr.x + data->dx[i];
			ny = curr.y + data->dy[i];
			if (!ft_check_bounds(nx, ny, data->map, data->cub->map.row))
				return (0);
			if (ft_is_walkable(data->map[ny][nx]))
			{
				data->array[(*(data->back))++] = (t_point){nx, ny};
				data->map[ny][nx] = 'V';
			}
			i++;
		}
	}
	return (1);
}

int	validate_map_walkability(t_all_struct *cub, char **map, t_point player)
{
	t_point			array[10000];
	t_fill_data		data;
	t_fill_state	state;

	state.front = 0;
	state.back = 0;
	init_directions(state.dx, state.dy);
	array[state.back++] = player;
	map[player.y][player.x] = 'V';
	data.map = map;
	data.array = array;
	data.front = &state.front;
	data.back = &state.back;
	data.cub = cub;
	data.dx = state.dx;
	data.dy = state.dy;
	if (!flood_fill(&data))
		return (0);
	return (1);
}

int	ft_check_map_validity(t_all_struct *cub)
{
	t_point		player;
	char		**map;
	int			valid;

	map = ft_copy_map(cub->map.real_map_two_d, cub->map.row);
	if (!map)
		return (0);
	if (!find_player(map, cub, &player))
	{
		free_two_d(map);
		return (0);
	}
	valid = validate_map_walkability(cub, map, player);
	free_two_d(map);
	return (valid);
}
