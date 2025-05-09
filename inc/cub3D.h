/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:39:31 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/08 19:20:30 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include <X11/keysym.h>
# include <ctype.h>
# include <string.h>
# include <mlx.h>

typedef struct s_point
{
    int x;
    int y;
} t_point;

typedef struct s_map
{
    // map store
    char    *map_one_d;
    char    **map_two_d;
    char    **real_map_two_d;
    char    *real_map_one_d;
    // map dimension
    int     row;
    int     col;
    int     start_of_map;
    int     end_of_map;
    // path texture
    int     index_north_line_no;
    char    path_north_no[100000];
    int     index_south_line_so;
    char    path_south_so[100000];
    int     index_west_line_we;
    char    path_west_we[100000];
    int     index_east_line_ea;
    char    path_east_ea[100000];
    int     num_paths;
    // color
    int     index_floor_color;
    int     floor_color[3];
    int     index_ceiling_color;
    int     ceiling_color[3];

    int x_player;
    int y_player;
} t_map;

typedef struct s_all_struct
{
    t_map map;
    t_point point;
} t_all_struct;


//check_map_content
void        check_chararcters(t_all_struct *cub_map);
void        wall_checker(t_all_struct *cub_map, int pos);
void        mid_wall_checker(t_all_struct *cub_map);
void        map_checker(t_all_struct *cub_map);

//get_map
void        get_and_copies_map(t_all_struct *cub_map, int fd);
char	    *join_lines(char *str, char *line, int fd);
char	    *reading_file(int fd);
void	    get_map(t_all_struct *cub_map, int fd);
int         map(t_all_struct *cub_map, int argc, char **argv);
char        *get_real_map_one_d(t_all_struct *cub_map);
char    	**get_real_map_two_d(t_all_struct *cub_map);

//check_argument
int         input_checker(int argc, char **argv);

//utils_map
int         count_col(t_all_struct *cub_map);
int         count_row(t_all_struct *cub_map) ;
int         count_start_of_map(t_all_struct *cub_map);
int         count_end_of_map(t_all_struct *cub_map);

//paths
void        check_north_path(t_all_struct *cub_map);
void        check_south_path(t_all_struct *cub_map);
void        check_west_path(t_all_struct *cub_map);
void        check_east_path(t_all_struct *cub_map);
void        check_befor_real_map(t_all_struct *cub_map);

//solve map
int	ft_check_map_validity(t_all_struct *cub);
int	ft_check_bounds(int x, int y, char **map, int rows);
char	**ft_copy_map(char **map, int rows);
int	ft_is_walkable(char c);
int	ft_is_player(char c);

//RGB color
void	    ceiling_color(t_all_struct *cub_map);
void	    floor_color(t_all_struct *cub_map);
int         is_valid_rgb(char **rgb);
char	    **split_rgb(char *s);

//exit and free all
void	    free_two_d(char **map_two_d);
void        free_all(t_all_struct *cub_map, int flag, char *error);
void        error_message(char *error);
int	input_checker(int argc, char **argv);

void last_wall_checker(t_all_struct *cub_map);
void print_struct(t_all_struct *cub_map);
#endif
