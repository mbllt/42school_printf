/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:22:29 by mballet           #+#    #+#             */
/*   Updated: 2021/03/18 10:08:37 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flags(t_flags *flag)
{
	flag->minus = 0;
	flag->zeroo = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->nbr_dot = -1;
	flag->star = 0;
}

int	treatment(const char *format, int i, va_list args, int nbr)
{
	int			nbr_printed;
	t_flags		*flag;

	flag = (t_flags *)malloc(sizeof(t_flags));
	if (!(flag))
		return (nbr *= -1);
	init_flags(flag);
	nbr_printed = 0;
	i++;
	while (ft_isflags(format[i]) == 1 || ft_isdigit(format[i]) == 1)
	{
		if (!(treat_flags(format, args, flag, i)))
			(nbr_printed *= -1);
		while (ft_isdigit(format[i]) == 1 && ft_isdigit(format[i + 1]) == 1)
			i++;
		i++;
	}
	if (ft_istype(format[i]) == 1)
		nbr_printed += treat_type(flag, format[i], args);
	free(flag);
	return ((nbr_printed));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		nbr_printed;

	va_start(args, format);
	nbr_printed = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] && nbr_printed >= 0)
		{
			nbr_printed += treatment(format, i, args, nbr_printed);
			i++;
			while (format[i + 1] && (ft_isflags(format[i]) == 1
					|| ft_isdigit(format[i]) == 1))
				i++;
		}
		else if (format[i] && nbr_printed >= 0)
		{
			write(1, &format[i], 1);
			nbr_printed++;
		}
	}
	va_end(args);
	return (nbr_printed);
}
