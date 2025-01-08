#PROJECT NAME
NAME = so_long

#PROJECT FILES
FILES = so_long.c file_handle.c tools/ft_strlen.c get_next_line.c get_next_line_utils.c tools/ft_strrchr.c tools/ft_strcmp.c \
		fill_map.c
#PROJECT DIRECTORIES
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))

#COMPILER
CC = cc
RM = rm -rf

#FLAGS
CFLAGS = -Wall -Wextra -Werror

#INCLUDES
INCLUDE = -I include 

#OBJECTS
OBJS = $(SRCS:.c=.o)

#RULES
all: $(NAME)

$(NAME): $(OBJS)
	make -C mlx_linux
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "Compiled "$<" successfully!"

clean:
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean:
	make -C ft_printf fclean
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all fclean clean re