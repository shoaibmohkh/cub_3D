/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:01:06 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 18:56:19 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_player(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (2);
	if (c == 'E')
		return (3);
	if (c == 'W')
		return (4);
	return (0);
}

int	ft_is_walkable(char c)
{
	return (c == '0' || c == ' ' || ft_is_player(c));
}

int	ft_check_bounds(int x, int y, char **map, int rows)
{
	if (y < 0 || y >= rows || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	return (1);
}

void	init_directions(int *dx, int *dy)
{
	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
}

char	**ft_copy_map(char **map, int rows)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

void	set_player(t_all_struct *cub, t_point *player, int x, int y, char dir)
{
	player->x = x;
	player->y = y;
	cub->map.x_player = x;
	cub->map.y_player = y;
	if (dir == 1)
		cub->map.start_direction_of_player = 'N';
	else if (dir == 2)
		cub->map.start_direction_of_player = 'S';
	else if (dir == 3)
		cub->map.start_direction_of_player = 'E';
	else if (dir == 4)
		cub->map.start_direction_of_player = 'W';
}

int	find_player(char **map, t_all_struct *cub, t_point *player)
{
	int	x;
	int	y;
	int	count;
	int	dir;

	y = 0;
	count = 0;
	while (y < cub->map.row)
	{
		x = 0;
		while (map[y][x])
		{
			dir = ft_is_player(map[y][x]);
			if (dir)
			{
				count++;
				set_player(cub, player, x, y, dir);
			}
			x++;
		}
		y++;
	}
	return (count == 1);
}

int	flood_fill(t_fill_data *data)
{
	t_point	curr;
	int		i;
	int		nx;
	int		ny;

	while (*(data->front) < *(data->back))
	{
		curr = data->queue[(*(data->front))++];
		i = 0;
		while (i < 4)
		{
			nx = curr.x + data->dx[i];
			ny = curr.y + data->dy[i];
			if (!ft_check_bounds(nx, ny, data->map, data->cub->map.row))
				return (0);
			if (ft_is_walkable(data->map[ny][nx]))
			{
				data->queue[(*(data->back))++] = (t_point){nx, ny};
				data->map[ny][nx] = 'V';
			}
			i++;
		}
	}
	return (1);
}

static int	validate_map_walkability(t_all_struct *cub, char **map, t_point player)
{
	t_point			queue[10000];
	t_fill_data		data;
	t_fill_state	state;

	state.front = 0;
	state.back = 0;
	init_directions(state.dx, state.dy);
	queue[state.back++] = player;
	map[player.y][player.x] = 'V';
	data.map = map;
	data.queue = queue;
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
		return (free_two_d(map), 0);
	valid = validate_map_walkability(cub, map, player);
	free_two_d(map);
	return (valid);
}


