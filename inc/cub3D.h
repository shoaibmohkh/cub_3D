#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include <X11/keysym.h>
# include <ctype.h>
# include <string.h>
# include "MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>

#define WIDTH 1000
#define HEIGHT 900
#define BLOCK 64
#define M_PI 3.14159265358979323846

typedef struct s_texture {
    mlx_texture_t *texture;
    mlx_image_t *img;
    int width;
    int height;
} t_texture;

typedef struct s_player {
    float x;
    float y;
    float angle;
    int key_up;
    int key_down;
    int key_left;
    int key_right;
    int left_rotate;
    int right_rotate;
} t_player;

typedef struct s_map {
    char *map_one_d;
    char **map_two_d;
    char **real_map_two_d;
    char *real_map_one_d;
    int row;
    int col;
    int start_of_map;
    int end_of_map;
    int index_north_line_no;
    char path_north_no[100000];
    int index_south_line_so;
    char path_south_so[100000];
    int index_west_line_we;
    char path_west_we[100000];
    int index_east_line_ea;
    char path_east_ea[100000];
    int num_paths;
    int index_floor_color;
    int floor_color[3];
    int ceiling_color[3];
    int index_ceiling_color;
    int x_player;
    int y_player;
    char start_direction_of_player;
} t_map;

typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_all_struct t_all_struct;

typedef struct s_game {
    mlx_t *mlx;
    mlx_image_t *img;
    char **map;
    t_all_struct *all_struct;
    t_texture north;
    t_texture south;
    t_texture east;
    t_texture west;
} t_game;

typedef struct s_all_struct {
    t_map map;
    t_point point;
    t_texture texture;
    t_game game;
    t_player player;
} t_all_struct;




char	**prepare_map_and_player(t_all_struct *cub, t_point *player);
int		count_and_store_player(char **map, t_all_struct *cub, t_point *player);
void	update_player_info(t_all_struct *cub, t_point *player, int x, int y, char c);
int		find_player_and_set_direction(char **map, t_all_struct *cub, t_point *player);
int		flood_fill_map(char **map, int rows, t_point *queue, int *back); 

float fixed_dist(float x1, float y1, float x2, float y2, t_all_struct *cub_map);
void draw_line(t_all_struct *cub_map, float ray_angle, int i);

void check_chararcters(t_all_struct *cub_map);
void wall_checker(t_all_struct *cub_map, int pos);
void mid_wall_checker(t_all_struct *cub_map);
void last_wall_checker(t_all_struct *cub_map);

void map_checker(t_all_struct *cub_map);
void get_and_copies_map(t_all_struct *cub_map, int fd);
char *join_lines(char *str, char *line, int fd);
char *reading_file(int fd);
void get_map(t_all_struct *cub_map, int fd);
int map(t_all_struct *cub_map, int argc, char **argv);

char *get_real_map_one_d(t_all_struct *cub_map);
char **get_real_map_two_d(t_all_struct *cub_map);

int input_checker(int argc, char **argv);
int count_col(t_all_struct *cub_map);
int count_row(t_all_struct *cub_map);
int count_start_of_map(t_all_struct *cub_map);
int count_end_of_map(t_all_struct *cub_map);

void check_north_path(t_all_struct *cub_map);
void check_south_path(t_all_struct *cub_map);
void check_west_path(t_all_struct *cub_map);
void check_east_path(t_all_struct *cub_map);
void check_befor_real_map(t_all_struct *cub_map);

int ft_check_map_validity(t_all_struct *cub);
int ft_check_bounds(int x, int y, char **map, int rows);
char **ft_copy_map(char **map, int rows);
int ft_is_walkable(char c);
int ft_is_player(char c);

void ceiling_color(t_all_struct *cub_map);
void floor_color(t_all_struct *cub_map);
int is_valid_rgb(char **rgb);
char **split_rgb(char *s);

void free_two_d(char **map_two_d);
void free_all(t_all_struct *cub_map, int flag, char *error);
void error_message(char *error);
void print_struct(t_all_struct *cub_map);

void fill_background(t_all_struct *cub_map);
void put_pixel(mlx_image_t *img, int x, int y, uint32_t color);

void init_player(t_all_struct *cub_map);
void key_press(mlx_key_data_t keydata, t_all_struct *cub_map);
void key_handler(mlx_key_data_t keydata, void *param);
bool touch(float px, float py, t_all_struct *cub_map);
void move_player(t_all_struct *cub_map);
void game_loop(void *param);
void init_game(t_all_struct *cub_map);
void cleanup(t_all_struct *cub_map);
float distance(float x, float y);
int load_texture(t_texture *tex, mlx_t *mlx, char *path, t_all_struct *cub_map);

#endif
