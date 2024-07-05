NAME = cub3D
NAME_BONUS = cub3D_bonus
INCLUDES = libft/include -I/usr/local/include
INCLUDES_BONUS = libft/include -I/usr/local/include
SRCS_DIR = src/
SRCS_DIR_BONUS = src_bonus/
OBJS_DIR = obj/
OBJS_DIR_BONUS = obj_bonus/
LIBFT = includes/libft
MLX42 = includes/MLX42
CC = clang
CFLAGS = -O2 -fsanitize=leak -g -I
MLXFLAGS = includes/MLX42/libmlx42.a -ldl -DEBUG=1 -Iinclude -lm -lglfw -L"usr/lib/x86_64-linux-gnu/"
RM = rm -f
AR = ar rcs

#---------Definición de color---------#

BLUE = \033[0;34m
GREEN = \033[0;32m
NC = \033[0m

#----------------SRC---------------#

MAIN = main

SRC_FILES = parser/error parser/gnl parser/parser parser/read_split parser/checks parser/checks_map parser/p_textures parser/init_struct\
			game/game_loop game/delete game/hooks game/movements game/new_raycaster game/ray_check game/draw_walls game/ft_draw_debug\
			textures/textures textures/tx_aux

SRC_FILES_BONUS = parser/error parser/gnl parser/parser parser/read_split parser/checks parser/checks_map parser/p_textures parser/init_struct\
			game/game_loop game/delete game/hooks game/movements game/new_raycaster game/ray_check game/draw_walls game/ft_draw_debug\
			textures/textures textures/tx_aux textures/tx_map

OBJS_SRC = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES) $(MAIN)))

OBJS_SRC_BONUS = $(addprefix $(OBJS_DIR_BONUS), $(addsuffix .o, $(SRC_FILES_BONUS) $(MAIN)))

OBJSF = $(OBJS_DIR)

OBJSF_BONUS = $(OBJS_DIR_BONUS)

all:$(NAME)

$(NAME):$(OBJSF)	$(OBJS_SRC)
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -s -C $(LIBFT)
	@make -s -C $(MLX42)
	@cp $(LIBFT)/libft.a .
	@cp $(MLX42)/libmlx42.a .
	@mv libft.a $(NAME)
	@mv libmlx42.a $(NAME)
	@echo "$(GREEN)Libft compiled!$(NC)"
	@echo "$(GREEN)MLX42 compiled!$(NC)"
	@echo "$(BLUE)Compiling $(NAME)...$(NC)"
	@$(CC) $(OBJS_SRC) $(LIBFLAG) $(MLXFLAGS) -o $(NAME) $(LIBFT)/libft.a
	@echo "$(GREEN)Succesful compilation!$(NC)"

bonus:$(OBJSF_BONUS)	$(OBJS_SRC_BONUS)
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -s -C $(LIBFT)
	@make -s -C $(MLX42)
	@cp $(LIBFT)/libft.a .
	@cp $(MLX42)/libmlx42.a .
	@mv libft.a $(NAME_BONUS)
	@mv libmlx42.a $(NAME_BONUS)
	@echo "$(GREEN)Libft compiled!$(NC)"
	@echo "$(GREEN)MLX42 compiled!$(NC)"
	@echo "$(BLUE)Compiling $(NAME_BONUS)...$(NC)"
	@$(CC) $(OBJS_SRC_BONUS) $(LIBFLAG) $(MLXFLAGS) -o $(NAME_BONUS) $(LIBFT)/libft.a
	@echo "$(GREEN)Succesful compilation!$(NC)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_BONUS)%.o : $(SRCS_DIR_BONUS)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)

$(OBJSF_BONUS):
	@mkdir -p $(OBJS_DIR_BONUS)

clean:
	@echo "$(BLUE)Cleaning...$(NC)"
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_DIR_BONUS)
	@make -s clean -C $(LIBFT)
	@make -s clean -C $(MLX42)
	@echo "$(GREEN)Cleaned$(NC)"

fclean: clean
	@echo "$(BLUE)Full cleaning...$(NC)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(RM) $(LIBFT)/libft.a
	@$(RM) $(MLX42)/libmlx42.a
	@echo "$(GREEN)Full cleaned$(NC)"

re: fclean all

.PHONY:re all fclean clean bonus