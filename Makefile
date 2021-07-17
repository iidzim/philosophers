# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:16:24 by iidzim            #+#    #+#              #
#    Updated: 2021/07/17 11:43:49 by iidzim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	sources/philo.c\
				sources/init.c\
				sources/to_do.c\
				sources/utils.c\
				sources/release.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address
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
				./philo 5 800 200 200
	