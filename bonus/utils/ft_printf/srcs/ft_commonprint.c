/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commonprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:34:05 by sgendel           #+#    #+#             */
/*   Updated: 2022/01/12 18:42:53 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char	*s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		i = 0;
		while (i < (ft_strlen(s)))
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (i);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		i;
	char	*nbr;

	i = 0;
	nbr = ft_itoa(n);
	i = ft_printstr(nbr);
	free (nbr);
	return (i);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
