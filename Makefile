# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:08:11 by vrybalko          #+#    #+#              #
#    Updated: 2017/02/12 20:15:00 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

IDIR = includes/

VPATH = src:includes

BIN_DIR = bin/

FLAGS = -O3 -Wall -Wextra -Werror -I$(IDIR)

FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit

FLAGS_X11 = -lmlx -lXext -lX11 -lm

LIB = libft/libft.a

SRCS = main.c					\
	   ft_img_px_put.c			\
	   ft_mlx_events.c			\
	   ft_mlx_init.c			\
	   ft_mundel.c				\
	   ft_put_info.c			\
	   ft_julia.c				\
	   ft_burning.c				\
	   ft_sinusoidal.c			\
	   ft_view.c				\
	   ft_koch.c				\
	   ft_mlx_helpers.c			\
	   ft_hooks.c


BINS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

$(NAME): makelib $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_X11) $(LIB)

$(BIN_DIR)%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

f: all
	./$(NAME) koch
