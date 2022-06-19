/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:16:34 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/19 21:41:17 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child1(char **argv, char **envp, int *fd)
{
	int	input;

	input = open(argv[1], O_RDONLY, 0777);
	if (input == -1)
		handler_of_errors(3);
	if (dup2(fd[1], 1) < 0)
		handler_of_errors(7);
	if (dup2(input, 0) < 0)
		handler_of_errors(7);
	close(fd[0]);
	exe_to_file(argv[2], envp);
}

void	child2(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output == -1)
		handler_of_errors(3);
	if (dup2(fd[0], 0) < 0)
		handler_of_errors(7);
	if (dup2(output, 1) < 0)
		handler_of_errors(7);
	close(fd[1]);
	exe_to_file(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	if (argc != 5)
		handler_of_errors(1);
	if (pipe(fd) == -1)
		handler_of_errors(4);
	pid[0] = fork();
	if (pid[0] == -1)
		handler_of_errors(5);
	else if (pid[0] == 0)
		child1(argv, envp, fd);
	else
	{
		pid[1] = fork();
		if (pid[1] == -1)
			handler_of_errors(5);
		else if (pid[1] == 0)
			child2(argv, envp, fd);
	}
	wait(NULL);
	return (0);
}
