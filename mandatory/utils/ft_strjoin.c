/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:46:32 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/11 20:54:23 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s1 || !s2)
		return (0);
	sub = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sub)
		return (0);
	i = 0;
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
			sub[i] = s1[i];
		if ((i >= ft_strlen(s1)) && (i < (ft_strlen(s1) + ft_strlen(s2))))
			sub[i] = s2[j++];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
