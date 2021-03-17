/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:10:05 by mballet           #+#    #+#             */
/*   Updated: 2021/03/17 16:44:51 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_counti(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	t;

	t = ft_strlen(base);
	i = 0;
	while (i < t - 1)
	{
		j = i + 1;
		while (j < t)
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		i++;
	}
	if (i < 1)
		return (-1);
	return (0);
}

void	ft_putnbrbs(unsigned long int nb, char **str, char *bs, int *a)
{
	unsigned long int	i;

	i = ft_counti(bs);
	if (ft_check_base(bs) != 0)
		return ;
	if (nb < i)
	{
		(*str)[*a] = bs[nb % i];
		*a = *a + 1;
	}
	if (nb >= i)
	{
		ft_putnbrbs(nb / i, str, bs, a);
		ft_putnbrbs(nb % i, str, bs, a);
	}
	(*str)[*a] = 0;
	return ;
}

long long int	ft_atoi_ll(const char *str)
{
	long long int		i;
	long unsigned int	res;
	long long int		neg;

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

int	ft_write_str(char **str)
{
	int	i;

	i = -1;
	while ((*str)[++i])
		write(1, &(*str)[i], 1);
	return (i);
}
