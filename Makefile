
NAME = cub3D
INCLUDES = libft/include -I/Users/$(USER)/.brew/opt/readline/include
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT = includes/libft
LIBFLAG = 
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I
MLXFLAGS = -Iinclude -Lincludes/MLX42/build -lmlx42 -ldl -lglfw -pthread -lm
RM = rm -f
AR = ar rcs

#---------Definición de color---------#

BLUE = \033[0;34m
GREEN = \033[0;32m
NC = \033[0m

#----------------SRC---------------#

MAIN = main

MAIN_DEBUG = main_debug

SRC_FILES = parser/error parser/gnl parser/parser parser/read_split parser/checks parser/dfs parser/checks_map parser/textures\
			game/game_loop

OBJS_SRC = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES) $(MAIN)))

OBJS_SRC_DEBUG = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES) $(MAIN_DEBUG)))

OBJSF = $(OBJS_DIR)

all:$(NAME)

$(NAME):$(OBJSF)	$(OBJS_SRC)
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -s -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@echo "$(GREEN)Libft compiled!$(NC)"
	@echo "$(BLUE)Compiling $(NAME)...$(NC)"
	@$(CC) $(OBJS_SRC) $(LIBFLAG) $(MLXFLAGS) -o $(NAME) $(LIBFT)/libft.a
	@echo "$(GREEN)Succesful compilation!$(NC)"

debug: $(OBJSF) $(OBJS_SRC_DEBUG)
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -s -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
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
	@echo "$(GREEN)Cleaned$(NC)"

fclean: clean
	@echo "$(BLUE)Full cleaning...$(NC)"
	@$(RM) $(NAME) $(NAME2)
	@$(RM) $(LIBFT)/libft.a
	@echo "$(GREEN)Full cleaned$(NC)"

re: fclean all

.PHONY:re all fclean clean bonus