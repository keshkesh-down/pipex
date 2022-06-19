/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:16:34 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/22 20:53:37 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	make_child(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		handler_of_errors(3);
	pid = fork();
	if (pid == -1)
		handler_of_errors(5);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exe_to_file(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc_child_proces(int	*fd, char	*limiter)
{
	char	*line;

	close(fd[0]);
	line = get_next_line(0);
	while (line != 0)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			exit(0);
		write(fd[1], line, ft_strlen(line));
		line = get_next_line(0);
	}
}

int	here_doc(char **argv, char *limiter, int argc)
{
	int		output;
	int		fd[2];
	pid_t	pid;

	output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (output < 0)
		handler_of_errors(2);
	if (pipe(fd) == -1)
		handler_of_errors(3);
	pid = fork();
	if (pid == 0)
		here_doc_child_proces(fd, limiter);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
	return (output);
}

int	main(int argc, char **argv, char **envp)
{
	int		output;
	int		input;
	int		i;

	i = 3;
	if (argc < 5)
		handler_of_errors(1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		output = here_doc(argv, argv[2], argc);
	else
	{
		i = 2;
		output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		input = open(argv[1], O_RDONLY, 0777);
		if ((input < 0) || (output < 0))
			handler_of_errors(2);
		if (dup2(input, 0) < 0)
			handler_of_errors(7);
	}
	while (i < argc - 2)
		make_child(argv[i++], envp);
	if (dup2(output, 1) < 0)
		handler_of_errors(7);
	exe_to_file(argv[argc - 2], envp);
}
