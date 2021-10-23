NAME = pipex

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./includes

RM = rm -rf

PATH_SRC = ./srcs/
PATH_MESSAGE = $(PATH_SRC)message/
PATH_INIT = $(PATH_SRC)init/
PATH_UTILS = $(PATH_SRC)utils/
PATH_EXEC = $(PATH_SRC)exec_functions/
PATH_INPUT = $(PATH_SRC)input_output/
PATH_GET = $(PATH_SRC)get_command/
PATH_OBJS= ./objs/

SRCS = $(PATH_MESSAGE)errors.c $(PATH_INIT)init_struct.c\
	$(PATH_UTILS)ft_strdup.c $(PATH_UTILS)ft_strjoin.c $(PATH_UTILS)ft_strlen.c\
	$(PATH_UTILS)ft_split.c $(PATH_UTILS)ft_calloc.c\
	$(PATH_EXEC)exec_functions.c\
	$(PATH_INPUT)input_functions.c\
	$(PATH_GET)get_path.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(PATH_SRC)pipex.c $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)get_command
	@mkdir -p $(PATH_OBJS)exec_functions
	@mkdir -p $(PATH_OBJS)input_output
	@mkdir -p $(PATH_OBJS)message
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)init
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) objs

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) $(PATH_OBJS) clean fclean re

