NAME			= libft.a

SRCS			= ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strlcat.c ft_strncmp.c ft_split.c ft_substr.c\
					ft_atoi.c ft_isalpha.c ft_bzero.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcpy.c \
					ft_calloc.c ft_isalpha.c  ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c \
					ft_strlen.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c ft_strjoin.c\
					ft_strtrim.c ft_itoa.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c \
					ft_striteri.c ft_read_fd.c ft_read_stdin.c ft_count_lines.c ft_count_lines2d.c ft_free2d.c ft_print_split.c \
					ft_cpy_2d.c ft_str_c_len.c

OBJS			= $(SRCS:.c=.o)

BONUS			= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

