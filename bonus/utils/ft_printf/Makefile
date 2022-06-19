# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:21:28 by sgendel           #+#    #+#              #
#    Updated: 2022/03/07 20:56:24 by sgendel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIST	=	srcs/ft_printf.c\
			srcs/ft_commonprint.c\
			srcs/ft_itoa.c\
			srcs/ft_strlen.c\

OBJ		=	$(patsubst %.c, %.o, $(LIST))

HEADER	= includes/ft_printf.h

CC		= cc

FLAGS	=	-Wall -Werror -Wextra

GREEN = \033[0;32m

RED = \033[0;31m

RESET = \033[0m

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME) :	$(OBJ) $(HEADER)
	@echo "\nft_printf: $(GREEN)object files were created$(RESET)"
	ar rcs $(NAME) $?
	@echo "ft_printf: $(GREEN)printf part was created$(RESET)"

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
