/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:41:51 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 22:06:11 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_two_d(char **map_two_d)
{
	int	i;

	if (!map_two_d)
		return ;
	i = 0;
	while ((map_two_d)[i])
	{
		free((map_two_d)[i]);
		i++;
	}
	free(map_two_d);
}

int	main(int argc, char **argv)
{
	t_map cub_map;

	ft_bzero(&cub_map, sizeof(t_map));
	if (map(&cub_map, argc, argv))
		return (1);
	printf("fdfd");
	return (0);
}