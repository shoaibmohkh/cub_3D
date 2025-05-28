/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:29:37 by zsalah            #+#    #+#             */
/*   Updated: 2025/05/28 14:07:35 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include "MLX42/MLX42.h"
# include <X11/keysym.h>
# include <ctype.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>

# define WIDTH 1000
# define HEIGHT 900
# define BLOCK 64
# define M_PI 3.14159265358979323846

typedef struct s_point		t_point;
typedef struct s_all_struct	t_all_struct;
typedef struct s_pos
{
	int						i;
	int						j;
}							t_pos;
typedef struct s_coord
{
	int						row;
	int						col;
}							t_coord;
typedef struct s_path_info
{
	char					*id;
	char					*dest;
	int						*index;
	char					*error_msg;
}							t_path_info;

typedef struct s_player_info
{
	t_all_struct			*cub;
	t_point					*player;
	int						x;
	int						y;
	int						dir;
}							t_player_info;
typedef struct s_fill_state
{
	int						dx[4];
	int						dy[4];
	int						front;
	int						back;
}							t_fill_state;

typedef struct s_fill_data
{
	char					**map;
	t_point					*array;
	int						*front;
	int						*back;
	t_all_struct			*cub;
	int						*dx;
	int						*dy;
}							t_fill_data;

typedef struct s_fpoint
{
	float					x;
	float					y;
}							t_fpoint;

typedef struct s_ray
{
	float					x;
	float					y;
	float					dir_x;
	float					dir_y;
}							t_ray;

typedef struct s_texture
{
	mlx_texture_t			*texture;
	mlx_image_t				*img;
	int						width;
	int						height;
}							t_texture;

typedef struct s_cast
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	float			side_x;
	float			side_y;
	float			delta_x;
	float			delta_y;
	int				side;
	float			distance;
	float			perp_dist;
	float			height;
	int				start_y;
	int				end_y;
	float			wall_x;
	int				tex_x;
	int				tex_y;
	float			tex_pos;
	float			step;
	t_texture		*tex;
}							t_cast;

typedef struct s_player
{
	float					x;
	float					y;
	float					angle;
	int						key_up;
	int						key_down;
	int						key_left;
	int						key_right;
	int						left_rotate;
	int						right_rotate;
}							t_player;

typedef struct s_map
{
	char					*map_one_d;
	char					**map_two_d;
	char					**real_map_two_d;
	char					*real_map_one_d;
	int						row;
	int						col;
	int						start_of_map;
	int						end_of_map;
	int						index_north_line_no;
	char					path_north_no[100000];
	int						index_south_line_so;
	char					path_south_so[100000];
	int						index_west_line_we;
	char					path_west_we[100000];
	int						index_east_line_ea;
	char					path_east_ea[100000];
	int						num_paths;
	int						index_floor_color;
	int						floor_color[3];
	int						ceiling_color[3];
	int						index_ceiling_color;
	int						x_player;
	int						y_player;
	char					start_direction_of_player;
}							t_map;

typedef struct s_point
{
	int						x;
	int						y;
}							t_point;

typedef struct s_all_struct	t_all_struct;

typedef struct s_game
{
	mlx_t					*mlx;
	mlx_image_t				*img;
	char					**map;
	t_player player;
	t_all_struct			*all_struct;
	t_texture				north;
	t_texture				south;
	t_texture				east;
	t_texture				west;
}							t_game;

typedef struct s_all_struct
{
	t_map					map;
	t_point					point;
	t_texture				texture;
	t_game					game;
	t_player				player;
	t_pos					pos;
}							t_all_struct;

typedef struct s_map_state
{
	int						line_start;
	int						newline_count;
	int						last_valid_line_newline;
}							t_map_state;

void 						draw_square(mlx_image_t *img, int x, int y, int size, uint32_t color, float scale);
void 						draw_map(t_game *game);
void 						draw_player(t_game *game);
void 						draw_minimap(t_all_struct *cub_map);
int							check_extension(char *filename);
int							input_checker(int argc, char **argv);
int							ft_is_player(char c);
void						check_required_elements(t_all_struct *cub_map);
int							validate_and_count_players(t_all_struct *cub_map);
void						check_chararcters(t_all_struct *cub_map);
void						wall_checker(t_all_struct *cub_map, int pos);
void						check_wall_start_indices(t_all_struct *cub_map);
void						check_wall_end_indices(t_all_struct *cub_map);
void						mid_wall_checker(t_all_struct *cub_map);
void						check_befor_real_map(t_all_struct *cub_map);
void						last_wall_checker(t_all_struct *cub_map);
void						check_north_path(t_all_struct *cub_map);
void						check_south_path(t_all_struct *cub_map);
void						check_west_path(t_all_struct *cub_map);
void						check_east_path(t_all_struct *cub_map);
int							ft_check_bounds(int x, int y, char **map, int rows);
void						init_directions(int *dx, int *dy);
char						**ft_copy_map(char **map, int rows);
void						set_player(t_player_info *info);
int							scan_row_for_player(char *row, int y,
								t_all_struct *cub, t_point *player);
int							is_valid_rgb_number(char *str);
int							is_valid_rgb(char **rgb);
int							assign_color(int *dest, char **rgb);
void						handle_color_line(t_all_struct *cub_map, char *line,
								int *color_array);
int							extract_path(t_all_struct *cub_map, int i, int j,
								char *dest);
int							is_valid_path_line(char **map_line, int j,
								char *id);
void						check_path(t_all_struct *cub_map,
								t_path_info *path_info);
int							ft_is_walkable(char c);
int							find_player(char **map, t_all_struct *cub,
								t_point *player);
int							flood_fill(t_fill_data *data);
int							validate_map_walkability(t_all_struct *cub,
								char **map, t_point player);
int							ft_check_map_validity(t_all_struct *cub);
char						**split_rgb_tokens(char *s, char ***tokens);
char						**split_rgb(char *s);
void						floor_color(t_all_struct *cub_map);
void						ceiling_color(t_all_struct *cub_map);
void						put_pixel(mlx_image_t *img, int x, int y,
								uint32_t color);
void						draw_half_screen(t_all_struct *cub_map, int start_y,
								int end_y, uint32_t color);
void						fill_background(t_all_struct *cub_map);
void						init_player(t_all_struct *cub_map);
void						key_press(mlx_key_data_t keydata,
								t_all_struct *cub_map);
void						key_handler(mlx_key_data_t keydata, void *param);
void						game_loop(void *param);
int							load_texture(t_texture *tex, mlx_t *mlx, char *path,
								t_all_struct *cub_map);
void						init_game(t_all_struct *cub_map);
void						delete_mlx(t_all_struct *cub_map);
int							touch(float px, float py, t_all_struct *cub_map);
void						handle_player_movement(t_all_struct *cub_map,
								float move_speed, float *new_x, float *new_y);
void						move_player(t_all_struct *cub_map);
void						init_deltas(t_cast *cast, t_ray *ray);
void						init_ray(t_ray *ray, t_all_struct *cub_map,
								float angle);
float						fixed_dist(t_fpoint from, t_fpoint to, float angle);
float						distance(float x, float y);
void						draw_line(t_all_struct *cub_map, float ray_angle,
								int i);
void						render_wall(t_all_struct *cub, t_cast *c, int i);
void						compute_tex_data(t_cast *c);
void						select_texture(t_cast *c, t_ray *r,
								t_all_struct *cub);
void						compute_wall_data(t_cast *c, t_ray *r,
								t_all_struct *cub);
void						init_steps(t_cast *cast, t_ray *ray);
void						perform_dda(t_cast *cast, t_all_struct *cub);
int							check_hit(t_cast *c, t_all_struct *cub);
float						compute_angle_and_distance(t_cast *c, t_ray *r,
								t_all_struct *cub);
void						compute_wall_diff_and_distance(t_cast *c, t_ray *r,
								t_all_struct *cub);
void						free_two_d(char **map_two_d);
void						error_message(char *error);
void						free_all(t_all_struct *cub_map, int flag,
								char *error);
char						*join_lines(char *str, char *line, int fd);
int							is_all_whitespace(const char *s);
char						*process_line(char *line, char *str, int fd);
char						*read_and_join_lines(int fd, char *str);
char						*reading_file(int fd);
void						get_and_copies_map(t_all_struct *cub_map, int fd);
void						get_map(t_all_struct *cub_map, int fd);
char						**allocate_and_fill_real_map(t_all_struct *cub_map,
								int len);
char						**get_real_map_two_d(t_all_struct *cub_map);
char						*get_real_map_one_d(t_all_struct *cub_map);
void						map_checker(t_all_struct *cub_map);
int							map(t_all_struct *cub_map, int argc, char **argv);
int							check_if_line_is_valid(t_all_struct *cub_map,
								int line_start, int end);
int							count_start_of_map(t_all_struct *cub_map);
int							count_col(t_all_struct *cub_map);
int							count_row(t_all_struct *cub_map);
int							count_end_of_map(t_all_struct *cub_map);
int							check_line_if_valid(t_all_struct *cub_map, int i,
								int line_start);
void						update_map_state(t_map_state *state, int i,
								int is_valid);
int							check_d_new_line(char **map_t, int start, int end);
char						**splitt(char *str);
int							count_start_of_tmap(char **map_two_d);
int							count_end_of_tmap(char **map_two_d);
int							is_map_line(char *line);
void						check_new_lines(t_all_struct *cub_map);
int							count_lines(char *str);
void						free_lines_on_error(char **lines, size_t limit);
#endif
