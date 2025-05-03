/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:39:31 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/03 22:54:15 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include <X11/keysym.h>
# include <mlx.h>

typedef struct s_map
{
    char    *map_one_d;
    char    **map_two_d;
    int     row;
    int     col;
    int     start_of_map;
    int     end_of_map;
    int     index_north_line_no;
    char     path_north_no[10000];
    int     index_south_line_so;
    char     path_south_so[10000];
    int     index_west_line_we;
    char     path_west_we[10000];
    int     index_east_line_ea;
    char     path_east_ea[10000];
} t_map;

//check_map_content
void        check_chararcters(t_map *cub_map);
void        wall_checker(t_map *cub_map);
void        mid_wall_checker(t_map *cub_map, int start_of_map);
void        map_checker(t_map *cub_map);

//get_map
char	    *join_lines(char *str, char *line, int fd);
char	    *reading_file(int fd);
void	    get_map(t_map *cub_map, int fd);
int         map(t_map *cub_map, int argc, char **argv);

//check_argument
int         input_checker(int argc, char **argv);

//utils_map
int         count_col(t_map *cub_map, int start_pos);
int         count_row(t_map *cub_map, int start_pos);
int         count_start_of_map(t_map *cub_map);

//paths
void        check_north_path(t_map *cub_map);
void        check_south_path(t_map *cub_map);
void        check_west_path(t_map *cub_map);
void        check_east_path(t_map *cub_map);

#endif