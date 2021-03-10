/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:10:05 by mballet           #+#    #+#             */
/*   Updated: 2021/03/10 10:50:39 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_counti(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		ft_check_base(char *base)
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

void	ft_putnbr_base(unsigned long int nbr, char **str, char *base, int *a)
{
	unsigned long int 		i;
	
	i = ft_counti(base);
	if (ft_check_base(base) != 0)
		return ;
	if (nbr < i)
	{
		(*str)[*a] = base[nbr % i];
		*a = *a + 1;
	}
	if (nbr >= i)
	{
		ft_putnbr_base(nbr / i, str, base, a);
		ft_putnbr_base(nbr % i, str, base, a);
	}
	(*str)[*a] = 0;
	return ;
}
long long int	ft_atoi_ll(const char *str)
{
	long long int				i;
	long unsigned int	res;
	long long int				neg;

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
