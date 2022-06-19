/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:32:48 by sgendel           #+#    #+#             */
/*   Updated: 2022/04/22 20:38:32 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static size_t	ft_size_part(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

int	countwords(char const	*s, char c)
{
	int	i;
	int	flag_of_end;
	int	count;

	i = 0;
	count = 0;
	flag_of_end = 1;
	while (s[i] != 0)
	{
		if (s[i] == c)
			flag_of_end = 1;
		else
		{
			if (flag_of_end == 1)
				count++;
			flag_of_end = 0;
		}
		i++;
	}
	return (count);
}

int	ft_split_free(char **arr_str, size_t word_cnt)
{
	while (word_cnt--)
		free(arr_str[word_cnt]);
	free(arr_str);
	return (0);
}

int	ft_split_part(char const *s, char c, char **arr_str)
{
	size_t	word_len;
	size_t	dsp;
	size_t	word_cnt;

	dsp = 0;
	word_cnt = 0;
	while (s[dsp] == c && c)
		dsp++;
	while (s[dsp])
	{
		word_len = ft_size_part((char *) s + dsp, c);
		arr_str[word_cnt] = malloc(sizeof(char) * (word_len + 1));
		if (arr_str[word_cnt] == NULL)
			return (ft_split_free(arr_str, word_cnt));
		ft_strlcpy(arr_str[word_cnt], s + dsp, word_len + 1);
		dsp += word_len;
		while (*(s + dsp) == c)
			++dsp;
		++word_cnt;
	}
	arr_str[word_cnt] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_str;

	if (!s)
		return (NULL);
	arr_str = (char **) malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (arr_str == (char **) 0)
		return (NULL);
	if (ft_split_part(s, c, arr_str) == 0)
		return (NULL);
	return (arr_str);
}
