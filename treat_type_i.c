/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:51:05 by mballet           #+#    #+#             */
/*   Updated: 2021/02/23 16:40:22 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	type_d_neg(char **str, int size)
{
	char	str_bis[size];
	int		i;
	int		a;
	int		b;

	i = 0;
	while ((*str)[i] == ' ')
		i++;
	a = 0;
	if (i > 0)
		while (a < i)
			str_bis[a++] = (*str)[i - 1];
	while ((*str)[i] == '0')
		i++;
	str_bis[a++] = (*str)[i++];
	while (a < i)
		str_bis[a++] = '0';
	while ((*str)[i])
		str_bis[a++] = (*str)[i++];
	str_bis[i] = 0;
	b = -1;
	while (str_bis[++b])
		(*str)[b] = str_bis[b];
	(*str)[b] = 0;
}

int			treat_type_i(t_flags *flag, int nbr_printed, va_list args, char c)
{
	int		ii;
	char	*str;
	int		size_type;
	int		i;

	size_type = 0;
	ii = va_arg(args, int);
	if (ii < 0)
		flag->nbr_dot++;
	str = ft_itoa(ii);
	if (str[0] == '0' && flag->nbr_dot == 0)
		str[0] = 0;
	if (flag->dot != 0 && !(flag_dot(&str, flag, c)))
		return ((nbr_printed *= -1));
	size_type = ft_strlen(str);
	if ((flag->width != 0 && !(flag_width(&str, flag, c))) ||
		(flag->minus == 1 && !(flag_minus(&str, size_type, flag))))
		return ((nbr_printed *= -1));
	if (ii < 0 && ((flag->width != 0 || flag->dot != 0) ||
		(flag->width != 0 && flag->dot != 0)))
		type_d_neg(&str, ft_strlen(str));
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	free(str);
	return ((nbr_printed + i));
}

