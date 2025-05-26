/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:02:13 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 20:16:21 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i -= 4;
	if (filename[i] == '.')
	{
		if (filename[i + 1] == 'c')
		{
			if (filename[i + 2] == 'u')
			{
				if (filename[i + 3] == 'b')
					return (0);
				else
					return (2);
			}
			else
				return (2);
		}
		else
			return (2);
	}
	else
		return (2);
}

int	input_checker(int argc, char **argv)
{
	int	r;

	r = 0;
	if (argc != 2)
	{
		printf("\033[1;31merror in MAP\033[0m 😤\n");
		return (1);
	}
	r = check_extension(argv[1]);
	if (r == 2)
		printf("\033[1;31merror in MAP\033[0m 😤\n");
	return (r);
}

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
