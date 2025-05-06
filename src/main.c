/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:41:51 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/06 17:32:49 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_all_struct cub_map;

	ft_bzero(&cub_map, sizeof(t_all_struct));
	if (map(&cub_map, argc, argv))
		return (1);
	printf("fdfd");
	return (0);
}
