/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:31:03 by mballet           #+#    #+#             */
/*   Updated: 2021/03/04 16:29:49 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*flag_minus(char **str, int size_type, t_flags *flag)
{
	char	*str_bis;
	int		size_str;
	int		a;
	int		b;

	size_str = ft_strlen(*str);
	if (!(str_bis = ft_strdup(*str)))
		return (NULL);
	ft_bzero(*str, size_str);
	a = 0;
	b = size_str - size_type;
	while (a < size_type)
	{
		(*str)[a++] = str_bis[b++];
	}
	while (a < size_str)
	{
		if (flag->zero == 1)
			(*str)[a++] = '0';
		else
			(*str)[a++] = ' ';
	}
	(*str)[a] = 0;
	free(str_bis);
	return (*str);
}

char		*flag_width(char **str, t_flags *flag, char c)
{
	char	*str_bis;
	int		a;
	int		b;

	if (flag->width > (int)ft_strlen(*str))
	{
		if (c == 'c' && (*str)[0] == 0)
			flag->width -= 1;
		if (!(str_bis = ft_strdup(*str)) ||
			!((*str) = ft_realloc(*str, (size_t)flag->width + 1)))
			return (NULL);
		a = 0;
		while (a < (flag->width - (int)ft_strlen(str_bis)))
			if (flag->zero == 1 || ((c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X') && (flag->zeroo == 1 && flag->nbr_dot < 0)))
				(*str)[a++] = '0';
			else
				(*str)[a++] = ' ';
		b = 0;
		while (a < flag->width)
			(*str)[a++] = str_bis[b++];
		(*str)[a] = 0;
		free(str_bis);
	}
	return (*str);
}

char		*flag_dot(char **str, t_flags *flag, char c)
{
	char	*str_bis;
	int		a;
	int		b;

	if (c == 'c' || c == 's')
		if (flag->nbr_dot < (int)ft_strlen(*str))
			if (!((*str) = ft_realloc((*str), flag->nbr_dot)))
				return (NULL);
	if ((c != 'c' && c != 's') && flag->nbr_dot > (int)ft_strlen(*str))
	{
		if (!(str_bis = ft_strdup(*str)) ||
			!((*str) = ft_realloc(*str, (size_t)flag->nbr_dot + 1)))
			return (NULL);
		ft_bzero(*str, ft_strlen(*str));
		a = 0;
		while (a < (flag->nbr_dot - (int)ft_strlen(str_bis)))
			(*str)[a++] = '0';
		b = 0;
		while (a < flag->nbr_dot)
			(*str)[a++] = str_bis[b++];
		(*str)[a] = 0;
		free(str_bis);
	}
	return (*str);
}
