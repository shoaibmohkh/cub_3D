/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:03:02 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 19:26:24 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update_map_state(t_map_state *state, int i, int is_valid)
{
	if (is_valid)
		state->last_valid_line_newline = state->newline_count;
	state->newline_count++;
	state->line_start = i + 1;
}

int	check_line_if_valid(t_all_struct *cub_map, int i, int line_start)
{
	int	end;

	if (cub_map->map.map_one_d[i] == '\n')
		end = i;
	else
		end = i + 1;
	return (check_if_line_is_valid(cub_map, line_start, end));
}

int	count_end_of_map(t_all_struct *cub_map)
{
	int			i;
	int			is_valid;
	t_map_state	state;

	i = 0;
	state.line_start = 0;
	state.newline_count = 0;
	state.last_valid_line_newline = 0;
	while (cub_map->map.map_one_d[i])
	{
		if (cub_map->map.map_one_d[i] == '\n'
			|| cub_map->map.map_one_d[i + 1] == '\0')
		{
			is_valid = check_line_if_valid(cub_map, i, state.line_start);
			update_map_state(&state, i, is_valid);
		}
		i++;
	}
	return (state.last_valid_line_newline);
}
