NAME = cub3D

SRCS = src/main.c src/get_full_map.c src/get_full_map_two.c src/utils_map.c \
	src/utils_map_two.c src/exit_and_free.c src/checker/check_double_new_line.c src/checker/check_double_new_line2.c \
	src/checker/check_argument.c src/checker/check_map_solve.c \
	src/checker/check_map_content.c src/checker/check_map_content_two.c \
	src/checker/check_map_paths.c src/checker/map_paths.c src/checker/map_solve_two.c \
	src/checker/check_rgb.c src/checker/rgb_color.c src/get_real_map.c \
	src/game/ray_cast.c src/game/ray_cast1.c src/game/ray_cast2.c src/game/mini_map.c \
	src/game/key_press.c src/game/move_player.c src/game/move_player2.c src/game/loop.c \
	src/game/floor_ceiling.c

OBJ_DIR = obj
OBJ = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = libft
MLX_PATH = MLX42
MLX_LIB = $(MLX_PATH)/build/libmlx42.a
MLX_FLAGS = -L$(MLX_PATH)/build -lmlx42 -ldl -lglfw -pthread -lm

CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -I./inc -I./libft/inc -I$(MLX_PATH)/include

LINKER = -L./libft -lft $(MLX_FLAGS)

RED = \033[0;38;5;160m
GREEN = \033[0;38;5;22m
DONE = \033[1;33m
RESET = \033[0m

all: LIB MLX $(NAME)
	@echo "🔥 $(GREEN) Compilation done successfully 🔥$(RESET)"
	@echo "        ☠️  $(DONE) hello cub3D ☠️$(RESET)"

LIB:
	@make -s -C $(LIBFT_PATH)

MLX:
	@cmake -S $(MLX_PATH) -B $(MLX_PATH)/build > /dev/null
	@cmake --build $(MLX_PATH)/build > /dev/null
	@echo "🔥 $(GREEN) Compilation done successfully 🔥$(RESET)"
	@echo "        ☠️  $(DONE) hello MLX42 ☠️$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $^ $(LINKER) -o $@

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIBFT_PATH) clean 
	@rm -rf $(MLX_PATH)/build
	@echo "$(RED)[CLEAN] Object and MLX build removed -cub3D- 🧹$(RESET)"

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make -s -C $(LIBFT_PATH) fclean
	@rm -rf $(MLX_PATH)/build
	@echo "$(RED)[FCLEAN] Everything removed -cub3D- 🧹$(RESET)"

re: fclean all

.PHONY: all clean fclean re LIB MLX

