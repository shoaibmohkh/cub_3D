/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:54:19 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/06 15:52:23 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_is_player(char c)
// {
// 	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
// }

// int	ft_is_walkable(char c)
// {
// 	return (c == '0' || c == ' ' || ft_is_player(c));
// }

// char	**ft_copy_map(char **map, int rows)
// {
// 	char	**copy;
// 	int		i;

// 	copy = malloc(sizeof(char *) * (rows + 1));
// 	if (!copy)
// 		return (NULL);
// 	i = 0;
// 	while (i < rows)
// 	{
// 		copy[i] = ft_strdup(map[i]);
// 		if (!copy[i])
// 		{
// 			while (--i >= 0)
// 				free(copy[i]);
// 			free(copy);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	copy[rows] = NULL;
// 	return (copy);
// }

// int	ft_check_bounds(int x, int y, char **map, int rows)
// {
// 	if (y < 0 || y >= rows || x < 0 || x >= (int)ft_strlen(map[y]))
// 		return (0);
// 	return (1);
// }


// int	ft_check_map_validity(t_map *cub)
// {
// 	t_point	queue[10000];
// 	int		front;
// 	int		back;
// 	t_point	curr;
// 	t_point	player;
// 	char	**map;
// 	int		dx[4];
// 	int		dy[4];
// 	int		i;
// 	int		nx;
// 	int		ny;
// 	int		player_count;

// 	dx[0] = 1; dx[1] = -1; dx[2] = 0; dx[3] = 0;
// 	dy[0] = 0; dy[1] = 0; dy[2] = 1; dy[3] = -1;
// 	map = ft_copy_map(cub->real_map_two_d, cub->row);
// 	if (!map)
// 		return (0);
// 	front = 0;
// 	back = 0;
// 	player_count = 0;
// 	player.x = -1;
// 	player.y = -1;
// 	for (int y = 0; y < cub->row; y++)
// 	{
// 		for (int x = 0; map[y][x]; x++)
// 		{
// 			if (ft_is_player(map[y][x]))
// 			{
// 				player_count++;
// 				player.x = x;
// 				player.y = y;
// 				cub->x_player = x;
// 				cub->y_player = y;
// 			}
// 		}
// 	}
// 	if (player_count != 1)
// 	{
// 		free_two_d(map);
// 		return (0);
// 	}
// 	queue[back++] = player;
// 	map[player.y][player.x] = 'V';
// 	while (front < back)
// 	{
// 		curr = queue[front++];
// 		i = 0;
// 		while (i < 4)
// 		{
// 			nx = curr.x + dx[i];
// 			ny = curr.y + dy[i];
// 			if (!ft_check_bounds(nx, ny, map, cub->row))
// 			{
// 				free_two_d(map);
// 				return (0);
// 			}
// 			if (ft_is_walkable(map[ny][nx]))
// 			{
// 				queue[back++] = (t_point){nx, ny};
// 				map[ny][nx] = 'V';
// 			}
// 			i++;
// 		}
// 	}
// 	free_two_d(map);
// 	return (1);
// }
