/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:44:55 by mballet           #+#    #+#             */
/*   Updated: 2021/03/17 16:43:00 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	size_itoa(unsigned int n)
{
	if (n >= 10)
		return (1 + (size_itoa(n / 10)));
	return (1);
}

static char	*fill_in_str(unsigned int n, char *str, int size)
{
	str[size] = '\0';
	size--;
	if (n == 0)
	{
		str[size] = n + 48;
	}
	while (n > 0)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	int		size;

	size = size_itoa(n);
	str = NULL;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	fill_in_str(n, str, size);
	return (str);
}
