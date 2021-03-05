/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:09:06 by mballet           #+#    #+#             */
/*   Updated: 2021/03/03 07:26:53 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_atoi(const char *str)
{
	int					i;
	long unsigned int	res;
	int					neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	if (str[i] == '+' && neg == 1)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
		if (str[i] < 48 || str[i] > 57)
			return (res * neg);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_realloc(char *str, size_t size)
{
	char	*str2;
	int		i;

	if (!str)
		return (NULL);
	if (!(str2 = malloc(sizeof(char) * size)))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (size > 0 && str[i] != '\0')
	{
		str2[i] = str[i];
		size--;
		i++;
	}
	str2[i] = 0;
	free(str);
	return (str2);
}
