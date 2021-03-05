/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:46:55 by mballet           #+#    #+#             */
/*   Updated: 2021/02/23 17:29:03 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*fill_in_str_null(char **str)
{
	(*str)[0] = '(';
	(*str)[1] = 'n';
	(*str)[2] = 'u';
	(*str)[3] = 'l';
	(*str)[4] = 'l';
	(*str)[5] = ')';
	(*str)[6] = 0;
	return (*str);
}

int			treat_type_s(t_flags *flag, int nbr_printed, va_list args, char c)
{
	char	*s;
	char	*str;
	int		i;
	int		size_type;

	s = va_arg(args, char*);
	if (!s)
	{
		if (!(str = malloc(sizeof(char) * 7)))
			return ((nbr_printed *= -1));
		str = fill_in_str_null(&str);
	}
	else if (!(str = ft_strdup(s)))
		return ((nbr_printed *= -1));
	if (flag->dot > 0 && !(flag_dot(&str, flag, c)))
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
