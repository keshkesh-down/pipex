# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 21:40:24 by sgendel           #+#    #+#              #
#    Updated: 2022/04/22 20:37:44 by sgendel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	../pipex

PATHSRCS		=	srcs/

PATHUTILS		=	utils/

LIST			=	./$(PATHSRCS)pipex_bonus.c\
					./$(PATHSRCS)pipex_utils_bonus.c\
					./$(PATHSRCS)handler_of_errors_bonus.c\
					./$(PATHUTILS)ft_split.c\
					./$(PATHUTILS)ft_strncmp.c\
					./$(PATHUTILS)ft_strlcpy.c\
					./$(PATHUTILS)get_next_line/get_next_line.c\
					./$(PATHUTILS)get_next_line/get_next_line_utils.c\

OBJ				=	$(patsubst %.c, %.o, $(LIST))

HEADER			=	includes/pipex.h

FLAGS			=	-Wall -Werror -Wextra

CC				=	cc

GREEN			=	\033[0;32m

RESET			=	\033[0m

PRINTF			=	./$(PATHUTILS)ft_printf

PRINTFLIB		=	./$(PATHUTILS)ft_printf/libftprintf.a

.PHONY:			all clean fclean re printf

all:			printf $(NAME)

printf:
	@make -C $(PRINTF) all

$(NAME):	$(OBJ) $(HEADER) $(PRINTFLIB)
	@echo "\npipex: $(GREEN)object files were created$(RESET)"
	$(CC) $(FLAGS) $(OBJ) $(LIBXF) $(PRINTFLIB) -o $(NAME)
	@echo "pipex: $(GREEN)pipex: mandatory part was created$(RESET)"

%.o: %.c	$(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make -C $(PRINTF) clean
	@rm -f $(OBJ)

fclean:		clean
	@make -C $(PRINTF) fclean
	@rm -f $(NAME)

re:			fclean all
