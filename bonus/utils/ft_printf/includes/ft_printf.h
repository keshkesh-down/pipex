/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:08:28 by sgendel           #+#    #+#             */
/*   Updated: 2022/02/24 20:10:23 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char	*s);
int		ft_putnbr(int n, int i);
size_t	ft_strlen(const char *s);
int		ft_printstr(char *s);
int		ft_printnbr(int n);
char	*ft_itoa(int n);
int		ft_printpercent(void);
#endif
