# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 05:04:24 by atudor            #+#    #+#              #
#    Updated: 2023/10/21 16:51:57 by atudor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/big_sort.c srcs/check_args.c srcs/inits.c \
srcs/libft_utils.c srcs/movements.c srcs/small_sort.c srcs/sort_utils.c
SRCSBONUS = #
 			
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}

NAME = push_swap
INCLUDE = includes/ft_push_swap.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g


# Implicit method
%.o:%.c 	$(INCLUDE) Makefile
			$(CC) $(CFLAGS) -c $< -o $@


# My methods
all: 		${NAME}

${NAME}:	${OBJS} ${INCLUDE}
			gcc  $(CFLAGS) ${OBJS} -o ${NAME} 

#bonus:		${OBJS} ${OBJSBONUS}
#			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
#			@touch bonus

clean: 		
#			${RM} ${OBJS} ${OBJSBONUS}
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}
			#${RM} bonus

re:			fclean all

.PHONY: all clean fclean re
