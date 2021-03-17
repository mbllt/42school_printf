/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:10:03 by mballet           #+#    #+#             */
/*   Updated: 2021/03/17 15:47:58 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	treat_type(t_flags *flag, char c, va_list args)
{
	int		nbr_printed;

	nbr_printed = 0;
	if (c == 'c')
		nbr_printed += treat_type_c(flag, nbr_printed, args, c);
	else if (c == 's')
		nbr_printed += treat_type_s(flag, nbr_printed, args, c);
	else if (c == 'd' || c == 'i')
		nbr_printed += treat_type_d(flag, nbr_printed, args, c);
	else if (c == 'p')
		nbr_printed += treat_type_p(flag, nbr_printed, args, c);
	else if (c == 'u')
		nbr_printed += treat_type_u(flag, nbr_printed, args, c);
	else if (c == 'x')
		nbr_printed += treat_type_x(flag, nbr_printed, args, c);
	else if (c == 'X')
		nbr_printed += treat_type_xc(flag, nbr_printed, args, c);
	else
		nbr_printed += treat_type_pourcent(flag, nbr_printed, c);
	return (nbr_printed);
}
