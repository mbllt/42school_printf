/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:47:26 by mballet           #+#    #+#             */
/*   Updated: 2021/03/22 08:56:08 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*add_prefix(char **str, t_flags *flag, uintptr_t p, int i)
{
	int		j;
	char	*temp;

	temp = ft_strdup(*str);
	if (*str)
	{
		(*str) = ft_realloc(*str, i + 3);
		if (!(*str))
			return (NULL);
		(*str)[0] = '0';
		(*str)[1] = 'x';
		if (flag->dot != 0 && flag->nbr_dot == 0 && p == 0)
		{
			(*str)[2] = 0;
			free(temp);
			return (*str);
		}
		j = 2;
		i = -1;
		while (temp[++i])
			(*str)[j++] = temp[i];
		(*str)[j] = 0;
		free(temp);
	}
	return (*str);
}

int	treat_type_p(t_flags *flag, int nbr_printed, va_list args, char c)
{
	uintptr_t		p;
	char			*str;
	int				size_type;
	int				i;
	int				a;

	a = 0;
	p = va_arg(args, uintptr_t);
	str = malloc(sizeof(char) * 17);
	if (!str)
		return ((nbr_printed *= -1));
	ft_putnbrbs(p, &str, "0123456789abcdef", &a);
	if (flag->dot != 0 && !(flag_dot(&str, flag, c)))
		return ((nbr_printed *= -1));
	size_type = ft_strlen(str);
	str = add_prefix(&str, flag, p, size_type);
	if (!str)
		return ((nbr_printed *= -1));
	size_type = ft_strlen(str);
	if ((flag->width != 0 && !(flag_width(&str, flag, c)))
		|| (flag->minus == 1 && !(flag_minus(&str, size_type, flag))))
		return ((nbr_printed *= -1));
	i = ft_write_str(&str);
	free(str);
	return ((nbr_printed + i));
}
