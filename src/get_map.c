/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:58:21 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/07 21:39:33 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char    *join_lines(char *str, char *line, int fd)
{
    (void)fd;
    char    *tmp;

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
        if (!str)
        {
            close(fd);
            free(line);
            exit(1);
        }
        free(line);
        line = get_next_line(fd);
	}
	close(fd);
	if (ft_strlen(str) == 0 || !str)//str[0] == '\n' ==> ft_strlen(str) == 0
	{
        printf("\033[1;31mmemory allocation fail:\033[0m in -join- 📛\n");
        free(str);
        exit (1);
	}
	return (str);
}

char	**get_real_map_two_d(t_all_struct *cub_map)
{
	char	**real_map;
	int		len;
	int		i;
	int		j;

	if (!cub_map->map.map_two_d || cub_map->map.start_of_map < 0)
        return (NULL);
	len = 0;
	while (cub_map->map.map_two_d[cub_map->map.start_of_map + len])
		len++;
	real_map = malloc(sizeof(char *) * (len + 1));
	if (!real_map)
		return (NULL);
	i = cub_map->map.start_of_map;
	j = 0;
	while (j < len)//cub_map->map.map_two_d[i] ==> j < len
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

char    *get_real_map_one_d(t_all_struct *cub_map)
{
    char    *joined;
    int     total_len;
    int     i;
    int     pos;

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
        ft_strlcpy(joined + pos, cub_map->map.real_map_two_d[i], ft_strlen(cub_map->map.real_map_two_d[i]) + 1);
        pos += ft_strlen(cub_map->map.real_map_two_d[i]);
        if (cub_map->map.real_map_two_d[i + 1])
            joined[pos++] = '\n';
        i++;
    }
    joined[pos] = '\0';
    return (joined);
}

void    get_and_copies_map(t_all_struct *cub_map, int fd)
{
    // get the map
    cub_map->map.map_one_d = reading_file(fd);
    if (!cub_map->map.map_one_d)
        free_all(cub_map, 1
            ,"\033[1;31Worng read:\033[0merror in reading map 📛\n");
    printf("------ map_one_d ------\n%s\n", cub_map->map.map_one_d);

    cub_map->map.map_two_d = ft_split(cub_map->map.map_one_d, '\n');
	if (!cub_map->map.map_two_d)
        free_all(cub_map, 1
            ,"\033[1;31mmemory allocation fail:\033[0m in -split- 📛\n");
    printf("------ map_two_d ------\n");
    for (int i = 0; cub_map->map.map_two_d[i]; i++)
        printf("[%d]: %s\n", i, cub_map->map.map_two_d[i]);

    // start of real map
    cub_map->map.start_of_map = count_start_of_map(cub_map);
    if (cub_map->map.start_of_map == -1)
		free_all(cub_map, 1, "error in map");
    printf("------ start_of_map ------\n%d\n", cub_map->map.start_of_map);

    // end of the real map
    cub_map->map.end_of_map = count_end_of_map(cub_map);
    if (cub_map->map.real_map_two_d < 0)
        free_all(cub_map, 1
            ,"\033[1;31mmemory allocation fail:\033[0m can't copy the map 📛\n");
    printf("------ end_of_map ------\n%d\n", cub_map->map.end_of_map);
    
	// copy real map
    cub_map->map.real_map_two_d = get_real_map_two_d(cub_map);
	if (!cub_map->map.real_map_two_d)
        free_all(cub_map, 1
            ,"\033[1;31mmemory allocation fail:\033[0m can't copy the map 📛\n");
    printf("------ real_map_two_d ------\n");
    for (int i = 0; cub_map->map.real_map_two_d[i]; i++)
        printf("[%d]: %s\n", i, cub_map->map.real_map_two_d[i]);

    cub_map->map.real_map_one_d = get_real_map_one_d(cub_map);
	if (!cub_map->map.real_map_one_d)
        free_all(cub_map, 1
            ,"\033[1;31mmemory allocation fail:\033[0m can't copy the map 📛\n");
    printf("------ real_map_one_d ------\n%s\n", cub_map->map.real_map_one_d);
}

void	get_map(t_all_struct *cub_map, int fd)
{
    get_and_copies_map(cub_map, fd);
    cub_map->map.col = count_col(cub_map);
    cub_map->map.row = count_row(cub_map);
}

int	map(t_all_struct *cub_map, int argc, char **argv)
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
