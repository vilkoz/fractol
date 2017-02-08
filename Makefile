# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:08:11 by vrybalko          #+#    #+#              #
#    Updated: 2017/02/08 19:05:59 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

IDIR = includes/

VPATH = src:includes

BIN_DIR = bin/

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit

FLAGS_X11 = -lmlx -lXext -lX11 -lm

LIB = libft/libft.a

SRCS = main.c					\
	   ft_img_px_put.c			\
	   ft_mlx_events.c			\
	   ft_mlx_init.c			\
	   ft_mundel.c				\
	   ft_put_info.c


BINS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

$(NAME): makelib $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)

$(BIN_DIR)%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
