/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:01:06 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 20:22:00 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	set_player(t_player_info *info)
{
	info->player->x = info->x;
	info->player->y = info->y;
	info->cub->map.x_player = info->x;
	info->cub->map.y_player = info->y;
	if (info->dir == 1)
		info->cub->map.start_direction_of_player = 'N';
	else if (info->dir == 2)
		info->cub->map.start_direction_of_player = 'S';
	else if (info->dir == 3)
		info->cub->map.start_direction_of_player = 'E';
	else if (info->dir == 4)
		info->cub->map.start_direction_of_player = 'W';
}

int	scan_row_for_player(char *row, int y, t_all_struct *cub, t_point *player)
{
	t_player_info	info;
	int				x;
	int				count;
	int				dir;

	x = 0;
	count = 0;
	while (row[x])
	{
		dir = ft_is_player(row[x]);
		if (dir)
		{
			count++;
			info.cub = cub;
			info.player = player;
			info.x = x;
			info.y = y;
			info.dir = dir;
			set_player(&info);
		}
		x++;
	}
	return (count);
}
