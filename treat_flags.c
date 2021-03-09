/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:06:11 by mballet           #+#    #+#             */
/*   Updated: 2021/03/04 16:29:55 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	treat_nbr_width_precision(const char *format, t_flags *flag, int i)
{
	char	str[ft_strlen(format)];
	int		b;
	int		z;

	z = 0;
	if (format[i - 1] == '.')
		z++;
	b = 0;
	while (ft_isdigit(format[i]) == 1)
		str[b++] = format[i++];
	str[b] = 0;
	if (z == 0)
		flag->width = ft_atoi(str);
	else
		flag->nbr_dot = ft_atoi(str);
}

static void	treat_flag_star(t_flags *flag, va_list args)
{
	flag->star += 1;

	if (flag->star == 1 && flag->dot == 0)
	{
		flag->width = va_arg(args, int);
		if (flag->width < 0)
		{
			flag->minus = 1;
			flag->width *= -1;
			flag->zero = 0;
		}
	}
	else
	{
		flag->nbr_dot = va_arg(args, int);
		if (flag->nbr_dot < 0)
			flag->dot = -1;
	}
	
}

void		treat_flags(const char *format, va_list args, t_flags *flag, int i)
{
	if (format[i] == '0' && flag->dot == 0 && flag->minus == 0)
	{
		flag->zeroo = 1;
		flag->zero = 1;
	}
	if (format[i] == '-' || format[i] == '.')
		flag->zero = 0;
	if (format[i] == '-')
		flag->minus = 1;
	if (ft_isdigit(format[i]) == 1)
		treat_nbr_width_precision(format, flag, i);
	if (format[i] == '.')
	{
		flag->dot = 1;
		flag->nbr_dot = 0;
		if (flag->width == 0)
			flag->minus = 0;
	}
	if (format[i] == '*')
		treat_flag_star(flag, args);
}
