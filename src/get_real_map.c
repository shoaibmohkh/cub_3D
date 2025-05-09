/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:08:05 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/08 22:46:05 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**allocate_and_fill_real_map(t_all_struct *cub_map, int len)
{
	char	**real_map;
	int		i;
	int		j;

	real_map = malloc(sizeof(char *) * (len + 1));
	if (!real_map)
		return (NULL);
	i = cub_map->map.start_of_map;
	j = 0;
	while (j < len)
	{
		real_map[j] = ft_strdup(cub_map->map.map_two_d[i]);
		if (!real_map[j])
		{
			free_two_d(real_map);
			return (NULL);
		}
		i++;
		j++;
	}
	real_map[j] = NULL;
	return (real_map);
}

char	**get_real_map_two_d(t_all_struct *cub_map)
{
	int	len;

	if (!cub_map->map.map_two_d || cub_map->map.start_of_map < 0)
		return (NULL);
	len = 0;
	while (cub_map->map.map_two_d[cub_map->map.start_of_map + len])
		len++;
	return (allocate_and_fill_real_map(cub_map, len));
}

char	*get_real_map_one_d(t_all_struct *cub_map)
{
	char	*joined;
	int		total_len;
	int		i;
	int		pos;

	total_len = 0;
	i = 0;
	while (cub_map->map.real_map_two_d[i])
		total_len += ft_strlen(cub_map->map.real_map_two_d[i++]) + 1;
	joined = malloc(total_len + 1);
	if (!joined)
		return (NULL);
	pos = 0;
	i = 0;
	while (cub_map->map.real_map_two_d[i])
	{
		ft_strlcpy(joined + pos, cub_map->map.real_map_two_d[i],
			ft_strlen(cub_map->map.real_map_two_d[i]) + 1);
		pos += ft_strlen(cub_map->map.real_map_two_d[i]);
		if (cub_map->map.real_map_two_d[i + 1])
			joined[pos++] = '\n';
		i++;
	}
	joined[pos] = '\0';
	return (joined);
}
