# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 21:39:31 by sgendel           #+#    #+#              #
#    Updated: 2022/04/22 20:39:50 by sgendel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY	=	./mandatory

BONUS		=	./bonus

.PHONY:		all bonus clean fclean re

all:
	@make -C $(MANDATORY) all

bonus:
	@make -C $(BONUS) all

clean:
	@make -C $(MANDATORY) clean
	@make -C $(BONUS) clean

fclean:
	@make -C $(MANDATORY) fclean
	@make -C $(BONUS) fclean

re:	fclean all
