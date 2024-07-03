NAME = cub3D
INCLUDES = libft/include -I/usr/local/include #PARA UBUNTU
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = includes/libft
MLX42 = includes/MLX42
LIBFLAG =
CC = clang
CFLAGS = -g -I
MLXFLAGS = includes/MLX42/libmlx42.a -ldl -DEBUG=1 -Iinclude -lm -lglfw -L"usr/lib/x86_64-linux-gnu/"
RM = rm -f
AR = ar rcs

#---------Definición de color---------#

BLUE = \033[0;34m
GREEN = \033[0;32m
NC = \033[0m

#----------------SRC---------------#

MAIN = main

MAIN_DEBUG = main

SRC_FILES = parser/error parser/gnl parser/parser parser/read_split parser/checks parser/dfs parser/checks_map parser/p_textures\
			game/game_loop game/textures game/hooks game/movements game/new_raycaster game/ray_check game/draw_walls game/ft_draw_debug

OBJS_SRC = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES) $(MAIN)))

OBJS_SRC_DEBUG = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES) $(MAIN_DEBUG)))

OBJSF = $(OBJS_DIR)

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

debug: $(OBJSF) $(OBJS_SRC_DEBUG)
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -s -C $(LIBFT)
	@make -s -C $(MLX42)
	@cp $(LIBFT)/libft.a .
	@cp $(MLX42)/libmlx42.a .
	@mv libft.a $(NAME)
	@mv libmlx42.a $(NAME)
	@echo "$(GREEN)Libft compiled!$(NC)"
	@echo "$(BLUE)Compiling $(NAME)...$(NC)"
	@$(CC) $(OBJS_SRC_DEBUG) $(LIBFLAG) $(MLXFLAGS) -o cub_debug $(LIBFT)/libft.a
	@echo "$(GREEN)Succesful compilation!$(NC)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "$(BLUE)Cleaning...$(NC)"
	@$(RM) -r $(OBJS_DIR)
	@make -s clean -C $(LIBFT)
	@make -s clean -C $(MLX42)
	@echo "$(GREEN)Cleaned$(NC)"

fclean: clean
	@echo "$(BLUE)Full cleaning...$(NC)"
	@$(RM) $(NAME) $(NAME2)
	@$(RM) $(LIBFT)/libft.a
	@$(RM) $(MLX42)/libmlx42.a
	@echo "$(GREEN)Full cleaned$(NC)"

re: fclean all

.PHONY:re all fclean clean bonus