/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:02:13 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 22:12:37 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	input_checker(int argc, char **argv)
{
	int	i;
	int	r;

	r = 0;
	i = 0;
	if (argc != 2)
	{
		printf("\033[1;31mwrong argumet:\033[0m error in number of argumet 🤔\n");
		return (1);
	}
	while (argv[1][i])
		i++;
	i -= 4;
	if (argv[1][i] == '.') // check the end name of file
	{
		if (argv[1][i + 1] == 'c')
		{
			if (argv[1][i + 2] == 'u')
			{
				if (argv[1][i + 3] == 'b')
					r = 0;
				else
					r = 2;
			}
			else
				r = 2;
		}
		else
			r = 2;
	}
	else
		r = 2;
	if (r == 2)
		printf("\033[1;31mwrong argumet:\033[0m error in name MAP 🤔\n");
	return (r);
}
