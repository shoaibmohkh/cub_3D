NAME =cub3D

SRCS =src/main.c src/get_map.c src/utils_map.c src/exit_and_free.c	src/checker/check_argument.c src/checker/check_map_content.c src/checker/map_paths.c src/checker/rgb_color.c
OBJ_DIR =obj
OBJ =$(SRCS:src/%.c=$(OBJ_DIR)/%.o)
LIBFT_PATH=libft
CC =cc 
CFLAGS =-Wall -Wextra -Werror -g
LINKER =-L./libft -lft -lmlx -lXext -lX11
INC =-I./inc -I./libft/inc
RED = \033[0;38;5;160m
GREEN = \033[0;38;5;22m
DONE = \033[1;33m
RESET = \033[0m

all: LIB $(NAME)
	@echo "🔥 $(GREEN) Compilation done successfully 🔥$(RESET)"
	@echo "        ☠️  $(DONE) hello cub3D ☠️$(RESET)"

LIB:
	@make -s -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	@$(CC) $^ $(LINKER) -o $@

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) $< -c -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIBFT_PATH) clean 
	@echo "$(RED)[CLEAN] Object files removed -cub3D- 🧹$(RESET)"

fclean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[CLEAN] Object files removed -cub3D- 🧹$(RESET)"
	@rm -rf $(NAME)
	@make -s -C $(LIBFT_PATH) fclean
	@echo "$(RED)[FCLEAN] Executable removed -cub3D- 🧹$(RESET)"

re: fclean all

.PHONY: all clean fclean re LIB
