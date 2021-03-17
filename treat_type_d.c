/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:44:31 by mballet           #+#    #+#             */
/*   Updated: 2021/03/17 15:46:02 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	gain_line(char **str, char *str_bis)
{
	int	a;

	a = -1;
	while (str_bis[++a])
		(*str)[a] = str_bis[a];
	(*str)[a] = 0;
}

static int	type_d_neg(char **str, int size)
{
	char	*str_bis;
	int		i;
	int		a;

	str_bis = malloc(sizeof(char) * size);
	if (!(str_bis))
		return (0);
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
	gain_line(str, str_bis);
	free(str_bis);
	return (1);
}

int	treat_type_d(t_flags *flag, int nbr_printed, va_list args, char c)
{
	int		d;
	char	*str;
	int		size_type;
	int		i;

	size_type = 0;
	d = va_arg(args, int);
	if (d < 0)
		flag->nbr_dot++;
	str = ft_itoa(d);
	if (str[0] == '0' && flag->nbr_dot == 0)
		str[0] = 0;
	if (flag->dot != 0 && !(flag_dot(&str, flag, c)))
		return ((nbr_printed *= -1));
	size_type = ft_strlen(str);
	if ((flag->width != 0 && !(flag_width(&str, flag, c)))
		|| (flag->minus == 1 && !(flag_minus(&str, size_type, flag))))
		return ((nbr_printed *= -1));
	if (d < 0 && ((flag->width != 0 || flag->dot != 0)
			|| (flag->width != 0 && flag->dot != 0)))
		if (!(type_d_neg(&str, ft_strlen(str))))
			return ((nbr_printed *= -1));
	i = ft_write_str(&str);
	free(str);
	return ((nbr_printed + i));
}
