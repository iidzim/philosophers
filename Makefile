# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:16:24 by iidzim            #+#    #+#              #
#    Updated: 2021/09/14 15:16:52 by iidzim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	sources/philo.c\
				sources/init.c\
				sources/to_do.c\
				sources/release.c\
				sources/utils.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
RM			=	rm -rf

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				@$(CC) $(SRCS) $(FLAGS) -o $(NAME)

clean		:
				@$(RM) $(OBJS)

fclean		:	clean
				@$(RM) $(NAME)

re			:	fclean all

run			:	re
				./philo 2 100 200 200 3
	