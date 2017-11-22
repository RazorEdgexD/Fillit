# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 13:28:10 by aosobliv          #+#    #+#              #
#    Updated: 2016/12/08 13:32:19 by aosobliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR)

SRCS = main.c						\
		ft_read_from_file.c			\
		ft_print_map.c				\
		ft_len_list.c				\
		ft_create_map.c				\
		ft_general_valid.c			\
		ft_print_error.c			\
		ft_fill_coord.c				\
		ft_create_list.c			\
		ft_putchar.c				\
		ft_putstr.c					\
		ft_strsplit.c				\
		ft_new_xy_pos.c				\
		ft_result.c					\

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
