/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:22:29 by mballet           #+#    #+#             */
/*   Updated: 2021/03/10 09:58:10 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		init_flags(t_flags *flag)
{
	flag->minus = 0;
	flag->zeroo = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->nbr_dot = -1;
	flag->star = 0;
}

int			treatment(const char *format, int i, va_list args, int nbr)
{
	int			nbr_printed;
	t_flags		*flag;

	if (!(flag = (t_flags *)malloc(sizeof(t_flags))))
		return (nbr *= -1);
	init_flags(flag);
	nbr_printed = 0;
	i++;
	while (ft_isflags(format[i]) == 1 || ft_isdigit(format[i]) == 1)
	{
		treat_flags(format, args, flag, i);
		while (ft_isdigit(format[i]) == 1 && ft_isdigit(format[i + 1]) == 1 )
			i++;
		i++;
	}
	if (ft_istype(format[i]) == 1)
	{
		nbr_printed += treat_type(flag, format[i], args);
		free(flag);
		return (nbr_printed);
	}
	else
		free(flag);
	return ((nbr *= -1));
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		nbr_printed;

	if (!format)
		return (-1);
	va_start(args, format);
	nbr_printed = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] && nbr_printed >= 0)
		{
			nbr_printed += treatment(format, i, args, nbr_printed);
			i++;
			while (ft_isflags(format[i]) == 1 || ft_isdigit(format[i]) == 1)
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
/*
int	main(void)
{
	int x;
	int y;

	x = 0;
	y = 0;
	setbuf(stdout, NULL);
	x = ft_printf("%0*.*d\n", 2, 1, 4);
	printf("myret%d\n", x);
	y = printf("%0*.*d\n", 2, 1, 4);
	printf("ret%d\n", y);
	return (0);
}*/
