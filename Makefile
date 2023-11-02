# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperron <aperron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 11:32:50 by aperron           #+#    #+#              #
#    Updated: 2023/11/02 15:30:48 by aperron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= ft_printf.c utils.c
OBJS		= $(SRCS:.c=.o)

all:		$(NAME) header

$(NAME):	$(OBJS) header
			@ar rcs $(NAME) $(OBJS)

clean:		header
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			@fclean $(NAME)

header:
			@echo "RUNNING..."

.PHONY:		all clean fclean re