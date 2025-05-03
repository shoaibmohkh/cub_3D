/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:58:21 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 22:25:57 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*join_lines(char *str, char *line, int fd)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, line);
	if (!str)
	{
		close(fd);
        printf("\033[1;31mmemory allocation fail:\033[0m in -join- 📛\n");
        free(tmp);
        exit (1);
	}
	free(tmp);
	return (str);
}

char	*reading_file(int fd)
{
	char	*line;
	char	*str;

	line = get_next_line(fd);
	str = ft_strdup("");
	if (!str)
	{
		close(fd);
        printf("\033[1;31mmemory allocation fail:\033[0m in -strdup- 📛\n");
        exit (1);
	}
	while (line)
	{
		str = join_lines(str, line, fd);
		free(line);
		line = get_next_line(fd);
	}
	if (str[0] == '\n' || !str)
	{
		close(fd);
        printf("\033[1;31mmemory allocation fail:\033[0m in -join- 📛\n");
        free(str);
        exit (1);
	}
	close(fd);
	return (str);
}

void	get_map(t_map *cub_map, int fd)
{
    cub_map->map_one_d = reading_file(fd);
    cub_map->map_two_d = ft_split(cub_map->map_one_d, '\n');
    if (!cub_map->map_two_d)
    {
        printf("\033[1;31mmemory allocation fail:\033[0m in -split- 📛\n");
        free_two_d(cub_map->map_two_d);
        free(cub_map->map_one_d);
        exit (1);
    }
    cub_map->start_of_map = count_start_of_map(cub_map);
    cub_map->col = count_col(cub_map, cub_map->start_of_map);
    cub_map->row = count_row(cub_map, cub_map->start_of_map);
}

int	map(t_map *cub_map, int argc, char **argv)
{
	int	fd;

	if (input_checker(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("\033[1;31mwrong argumet:\033[0m error in map file -can't open it- ⛓️‍💥\n");
        exit(1);
	}
	get_map(cub_map, fd);
    map_checker(cub_map);
    return (0);
}
