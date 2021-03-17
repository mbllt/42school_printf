/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:29:39 by mballet           #+#    #+#             */
/*   Updated: 2021/03/17 16:40:30 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isflags(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}

int	ft_istype(char c)
{
	if (c == 'd' || c == 'i' || c == 'p' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'c' || c == 's' || c == '%')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;

	c = (unsigned char *)s;
	while (n-- > 0)
		c[n] = 0;
}
