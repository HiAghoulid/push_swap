# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:55:26 by haghouli          #+#    #+#              #
#    Updated: 2022/12/12 19:47:29 by haghouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap_ar
CC		= 	cc
CFLAGS	= 	-Wall -Wextra -Werror

FILES	= 	./rules/push.c \
			./rules/swap.c \
			./rules/rotate.c \
			./rules/reverse_rotate.c \
			./utiles/is_dup.c \
			./utiles/ft_atoi.c \
			./utiles/is_sorted.c \
			./utiles/is_int.c \
			./utiles/is_error.c \
			./utiles/ft_putstr.c \
			./utiles/fill_stack.c \
			./utiles/ft_cpy.c \
			./lst/lst_op.c \
			./utiles/ft_cpy.c \
			./utiles/find_max.c \
			./utiles/find_min.c \
			./utiles/is_sorted_dec.c \
			./sorts/lthree_sort.c \
			./sorts/sort.c \
			./utiles/index_lst.c \
			./checker/gnl/get_next_line.c \
			./checker/gnl/get_next_line_utils.c \
			./checker/ft_split.c \
			./checker/ft_strjoin.c \
			./checker/ft_strlen.c \
			./checker/ft_strdup.c \
			#./sorts/lfive_sort.c \#



OBJS		= $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) 

re : fclean all

reclean : re
	rm -f $(OBJS)
c : reclean
	gcc push_swap.c $(NAME) -o push_swap
