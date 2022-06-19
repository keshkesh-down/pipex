/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_of_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:35:23 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/18 16:36:27 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handler_of_errors(int code)
{
	if (code == 1)
		perror("\033[31mError: ./pipex <f1> <\"cmd1\"> <\"cmd2\"> <f2>\n\e[0m");
	if (code == 2)
		perror("\033[31mError: Bad command\n\e[0m");
	if (code == 3)
		perror("\033[31mError: File open error\n\e[0m");
	if (code == 4)
		perror("\033[31mError: Pipe error\n\e[0m");
	if (code == 5)
		perror("\033[31mError: Fork error\n\e[0m");
	if (code == 6)
		perror("\033[31mError: execve error\n\e[0m");
	if (code == 7)
		perror("\033[31mError: dup2 error\n\e[0m");
	exit(1);
}
