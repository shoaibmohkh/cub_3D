/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_map_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:05:14 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 19:13:10 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*join_lines(char *str, char *line, int fd)
{
	char	*tmp;

	(void)fd;
	tmp = str;
	str = ft_strjoin(str, line);
	if (!str)
	{
		printf("\033[1;31mmemory allocation fail:\033[0m in -strjoin- 📛\n");
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (str);
}

int	is_all_whitespace(const char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

char	*process_line(char *line, char *str, int fd)
{
	char	*trimmed;

	if (is_all_whitespace(line))
	{
		trimmed = ft_strtrim(line, " \t");
		free(line);
		line = trimmed;
		if (!line)
		{
			close(fd);
			free(str);
			exit(1);
		}
	}
	str = join_lines(str, line, fd);
	free(line);
	if (!str)
	{
		close(fd);
		exit(1);
	}
	return (str);
}
