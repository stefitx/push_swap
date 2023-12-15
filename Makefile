# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 05:04:24 by atudor            #+#    #+#              #
#    Updated: 2023/12/05 18:52:28 by atudor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/check_args.c srcs/inits.c \
srcs/libft_utils.c srcs/movements.c srcs/small_sort.c srcs/sort_utils.c \
srcs/chunks_sort.c
SRCSBONUS = bonus/main.c bonus/check_args.c bonus/inits.c \
bonus/libft_utils.c bonus/movements.c \
bonus/sort_utils.c \
includes/get_next_line/get_next_line.c \
includes/get_next_line/get_next_line_utils.c \
bonus/checker.c
 			
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}

NAME = push_swap
NAME_BONUS = checker
INCLUDE = includes/ft_push_swap.h
INCLUDE_BONUS = includes/get_next_line/get_next_line.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g


# Implicit method
%.o:%.c $(INCLUDE) $(INCLUDE_BONUS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@


# My methods
all: 		${NAME}

${NAME}:	${OBJS} ${INCLUDE}
			gcc  $(CFLAGS) ${OBJS} -o ${NAME} 

${NAME_BONUS}:	${OBJS} ${OBJSBONUS} ${INCLUDE_BONUS}
			gcc  $(CFLAGS) ${OBJSBONUS} -o ${NAME_BONUS} 

bonus:		 ${NAME_BONUS}
			@touch bonus

clean: 		
			${RM} ${OBJS} ${OBJSBONUS}
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}
			${RM} ${NAME_BONUS}

re:			fclean all

.PHONY: all clean fclean re bonus
