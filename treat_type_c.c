/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:46:43 by mballet           #+#    #+#             */
/*   Updated: 2021/03/16 18:30:58 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	flag_c(t_flags *flag)
{
	flag->minus = 2;
	return (0);
}

int			treat_type_c(t_flags *flag, int nbr_prt, va_list args, char c)
{
	char	*str;
	int		cc;
	int		i;

	cc = va_arg(args, int);
	if (!(str = malloc(sizeof(char) * 2 + 1)))
		return ((nbr_prt *= -1));
	i = 0;
	str[i] = (char)cc;
	str[i + 1] = 0;
	if ((flag->zero == 1 || flag->nbr_dot > 0) ||
		(flag->width != 0 && !(flag_width(&str, flag, c))) ||
		(flag->minus == 1 && flag->width != 0 && !(flag_minus(&str, 1, flag))))
		return ((nbr_prt *= -1));
	while (str[i])
		if (cc == 0 && flag->minus == 1 && !flag_c(flag))
			write(1, "\0", 1);
		else
			write(1, &str[i++], 1);
	if ((cc == 0 && flag->minus == 0) || (cc == 0 && str[0] == 0))
		write(1, "\0", 1);
	free(str);
	if (cc == 0)
		return ((nbr_prt + i + 1));
	return ((nbr_prt + i));
}
