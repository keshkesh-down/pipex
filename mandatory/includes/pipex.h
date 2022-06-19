/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:18:46 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/19 19:09:16 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h> //read, write, access, dup, dup2, execve, fork, pipe
# include <fcntl.h> //open, close
# include <stdlib.h> //malloc, free, exit
# include <stdio.h> //perror
# include <string.h> //strerror
# include <sys/wait.h> //wait, waitpid

void	handler_of_errors(int code);
char	*find_path(char **envp, char *cmd);
void	exe_to_file(char *argv, char **envp);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
#endif
