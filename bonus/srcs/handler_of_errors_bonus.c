/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_of_errors_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:35:23 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/22 20:52:16 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handler_of_errors(int code)
{
	if (code == 1)
		ft_printf("%s%s%s%s", "\033[31mError: Bad arguments\n\e[0m", \
		"Ex: ./pipex <file1> <\"cmd1\"> ... <\"cmd n\"> <file2>\n", \
		"\033[31mor\n\e[0m", \
		"Ex: ./pipex here_doc DELIMETR <\"cmd1\"> <\"cmd2\"> <file1>\n");
	if (code == 2)
		ft_printf("%s", "\033[31mError:\e[0m File open error\n");
	if (code == 3)
		ft_printf("%s", "\033[31mError:\e[0m Pipe error\n");
	if (code == 4)
		ft_printf("%s", "\033[31mError:\e[0m Bad command\n");
	if (code == 5)
		ft_printf("%s", "\033[31mError:\e[0m Fork error\n");
	if (code == 6)
		ft_printf("%s", "\033[31mError:\e[0m execve error\n");
	if (code == 7)
		ft_printf("%s", "\033[31mError:\e[0m dup2 error\n");
	exit(0);
}
