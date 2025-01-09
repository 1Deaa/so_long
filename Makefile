#PROJECT NAME
NAME = so_long

#PROJECT FILES
FILES = gnl/get_next_line.c gnl/get_next_line_util.c \
		tools/ft_strcmp.c tools/ft_strlen.c tools/ft_strrchr.c tools/open_file.c tools/ft_strcpy.c \
		file_handle.c file_handle_util.c fill_map.c map_handle.c map_handle_util.c map_init.c so_long.c
#PROJECT DIRECTORIES
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))

#COMPILER
CC = cc
RM = rm -rf

#FLAGS
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory

#INCLUDES
INCLUDE = -I include 

#COLORS
DEF_COLOR = \e[1;39m
RESET = \e[0m
GRAY = \e[1;90m
RED = \e[1;91m
YELLOW = \e[1;93m
GREEN = \e[1;92m
BLUE = \e[1;94m
MAGENTA = \e[1;95m
CYAN = \e[1;96m
WHITE = \e[1;97m
BLINK = \e[5m

#OBJECTS
OBJS = $(SRCS:.c=.o)

#RULES
all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf
	@echo "$(GREEN)█▀ █▀█    █   █▀█ █▄ █ █▀▀"
	@echo "$(GREEN)▄█ █▄█ ▄▄ █▄▄ █▄█ █ ▀█ █▄█"
	@$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)✔ $(MAGENTA)created $(GREEN)./so_long $(MAGENTA)succesfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(WHITE)· $(YELLOW)compiling file: $(BLINK)○$(RESET)"

clean:
	@make -C ft_printf clean
	@$(RM) $(OBJS)

fclean:
	@make -C ft_printf fclean
	@$(RM) $(OBJS) $(NAME)
	@echo "$(WHITE)·$(RED) ./$(NAME) was deleted!$(RESET)"


re: fclean all

.PHONY: all fclean clean re