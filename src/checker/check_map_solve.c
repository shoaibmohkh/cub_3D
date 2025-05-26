/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:01:06 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 16:30:20 by sal-kawa         ###   ########.fr       */
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

char	**ft_copy_map(char **map, int rows)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
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

int	ft_check_bounds(int x, int y, char **map, int rows)
{
	if (y < 0 || y >= rows || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	return (1);
}

int	ft_check_map_validity(t_all_struct *cub)
{
	t_point	queue[10000];
	int		front;
	int		back;
	t_point	curr;
	t_point	player;
	char	**map;
	int		dx[4];
	int		dy[4];
	int		i;
	int		nx;
	int		ny;
	int		player_count;

	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
	map = ft_copy_map(cub->map.real_map_two_d, cub->map.row);
	if (!map)
		return (0);
	front = 0;
	back = 0;
	player_count = 0;
	player.x = -1;
	player.y = -1;
	for (int y = 0; y < cub->map.row; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (ft_is_player(map[y][x]))
			{
				player_count++;
				player.x = x;
				player.y = y;
				cub->map.x_player = x;
				cub->map.y_player = y;
				if (ft_is_player(map[y][x]) == 1)
					cub->map.start_direction_of_player = 'N';
				if (ft_is_player(map[y][x]) == 2)
					cub->map.start_direction_of_player = 'S';
				if (ft_is_player(map[y][x]) == 3)
					cub->map.start_direction_of_player = 'E';
				if (ft_is_player(map[y][x]) == 4)
					cub->map.start_direction_of_player = 'W';
			}
		}
	}
	if (player_count != 1)
	{
		free_two_d(map);
		return (0);
	}
	queue[back++] = player;
	map[player.y][player.x] = 'V';
	while (front < back)
	{
		curr = queue[front++];
		i = 0;
		while (i < 4)
		{
			nx = curr.x + dx[i];
			ny = curr.y + dy[i];
			if (!ft_check_bounds(nx, ny, map, cub->map.row))
			{
				free_two_d(map);
				return (0);
			}
			if (ft_is_walkable(map[ny][nx]))
			{
				queue[back++] = (t_point){nx, ny};
				map[ny][nx] = 'V';
			}
			i++;
		}
	}
	free_two_d(map);
	return (1);
}
