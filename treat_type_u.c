/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:44:55 by mballet           #+#    #+#             */
/*   Updated: 2021/03/04 11:26:44 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			treat_type_u(t_flags *flag, int nbr_printed, va_list args, char c)
{
	unsigned int		u;
	char			*str;
	int				size_type;
	int				i;

	size_type = 0;
	u = va_arg(args, unsigned int);
	str = ft_itoa_unsigned(u);
	if (str[0] == '0' && flag->nbr_dot == 0)
		str[0] = 0;
	if (flag->dot != 0 && !(flag_dot(&str, flag, c)))
		return ((nbr_printed *= -1));
	size_type = ft_strlen(str);
	if ((flag->width != 0 && !(flag_width(&str, flag, c))) ||
		(flag->minus == 1 && !(flag_minus(&str, size_type, flag))))
		return ((nbr_printed *= -1));
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	free(str);
	return ((nbr_printed + i));
}
