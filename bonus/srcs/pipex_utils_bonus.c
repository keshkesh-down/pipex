/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:04:59 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/22 20:54:33 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**correct_envp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	correct_envp = ft_split(envp[i] + 5, ':');
	i = 0;
	while (correct_envp[i])
	{
		correct_envp[i] = ft_strjoin(correct_envp[i], "/");
		correct_envp[i] = ft_strjoin(correct_envp[i], cmd);
		if (access(correct_envp[i], F_OK) == 0)
		{
			path = correct_envp[i];
			free(correct_envp);
			return (path);
		}
		free(correct_envp[i]);
		i++;
	}
	i = 0;
	free(correct_envp);
	return (0);
}

void	exe_to_file(char *argv, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = find_path(envp, cmd[0]);
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		handler_of_errors(4);
	}
	if (execve(path, cmd, envp) == -1)
		handler_of_errors(6);
}
