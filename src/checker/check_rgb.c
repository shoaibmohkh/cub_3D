/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:17:45 by zsalah            #+#    #+#             */
/*   Updated: 2025/05/26 20:18:16 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_rgb_number(char *str)
{
	int	j;

	if (!str || !*str)
		return (0);
	j = 0;
	while (str[j])
	{
		if (!ft_isdigit(str[j]))
			return (0);
		j++;
	}
	return (1);
}

int	is_valid_rgb(char **rgb)
{
	int	i;
	int	val;

	if (!rgb)
		return (0);
	i = 0;
	while (i < 3)
	{
		if (!is_valid_rgb_number(rgb[i]))
			return (0);
		val = ft_atoi(rgb[i]);
		if (val < 0 || val > 255)
			return (0);
		i++;
	}
	return (1);
}

int	assign_color(int *dest, char **rgb)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		dest[j] = ft_atoi(rgb[j]);
		j++;
	}
	return (1);
}

void	handle_color_line(t_all_struct *cub_map, char *line, int *color_array)
{
	char	**rgb;

	rgb = split_rgb(line + 2);
	free(line);
	if (!rgb || !is_valid_rgb(rgb))
	{
		free_two_d(rgb);
		free_all(cub_map, 1, "\033[1;31merror in MAP\033[0m 😤\n");
	}
	assign_color(color_array, rgb);
	free_two_d(rgb);
}
