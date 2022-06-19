# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 21:40:24 by sgendel           #+#    #+#              #
#    Updated: 2022/04/22 20:43:35 by sgendel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	../pipex

PATHSRCS		=	srcs/

PATHUTILS		=	utils/

LIST			=	./$(PATHSRCS)pipex.c\
					./$(PATHSRCS)pipex_utils.c\
					./$(PATHSRCS)handler_of_errors.c\
					./$(PATHUTILS)ft_split.c\
					./$(PATHUTILS)ft_strncmp.c\
					./$(PATHUTILS)ft_strlcpy.c\
					./$(PATHUTILS)ft_strjoin.c\
					./$(PATHUTILS)ft_strlen.c\

OBJ				=	$(patsubst %.c, %.o, $(LIST))

HEADER			=	includes/pipex.h

FLAGS			=	-Wall -Werror -Wextra

CC				=	cc

GREEN			=	\033[0;32m

RESET			=	\033[0m

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	@echo "\npipex: $(GREEN)object files were created$(RESET)"
	$(CC) $(FLAGS) $(OBJ) $(LIBXF) -o $(NAME)
	@echo "pipex: $(GREEN)pipex: mandatory part was created$(RESET)"

%.o: %.c	$(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
