/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:45:10 by mballet           #+#    #+#             */
/*   Updated: 2021/03/11 15:48:43 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			treat_type_x(t_flags *flag, int nbr_printed, va_list args, char c)
{
	unsigned int	x;
	char			*str;
	int				size_type;
	int				i;
	int				a;

	a = 0;
	size_type = 0;
	x = va_arg(args, unsigned int);
	str = ft_itoa_unsigned(x);
	ft_putnbrbs(ft_atoi_ll(str), &str, "0123456789abcdef", &a);
	if (!(str))
		return ((nbr_printed *= -1));
	if (str[0] == '0' && flag->nbr_dot == 0)
		str[0] = 0;
	if (flag->dot != 0 && !(flag_dot(&str, flag, c)))
		return ((nbr_printed *= -1));
	size_type = ft_strlen(str);
	if ((flag->width != 0 && !(flag_width(&str, flag, c))) ||
		(flag->minus == 1 && !(flag_minus(&str, size_type, flag))))
		return ((nbr_printed *= -1));
	i = ft_write_str(&str);
	free(str);
	return ((nbr_printed + i));
}
