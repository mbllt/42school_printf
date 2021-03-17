/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:47:45 by mballet           #+#    #+#             */
/*   Updated: 2021/03/17 16:55:56 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_flags
{
	int			minus;
	int			zeroo;
	int			zero;
	int			width;
	int			dot;
	int			nbr_dot;
	int			star;
}				t_flags;
int				ft_printf(const char *format, ...);
int				treatment(const char *format, int i, va_list args, int nbr);
void			init_flags(t_flags *flag);
int				treat_flags(const char *format, va_list args,
					t_flags *flag, int i);
char			*flag_width(char **str, t_flags *flag, char c);
char			*flag_minus(char **str, int size_type, t_flags *flag);
char			*flag_dot(char **str, t_flags *flag, char c);
int				treat_type(t_flags *flag, char c, va_list args);
int				treat_type_c(t_flags *flag, int nbr_printed,
					va_list args, char c);
int				treat_type_s(t_flags *flag, int nbr_printed,
					va_list args, char c);
int				treat_type_p(t_flags *flag, int nbr_printed,
					va_list args, char c);
int				treat_type_d(t_flags *flag, int nbr_printed,
					va_list args, char c);
int				treat_type_u(t_flags *flag, int nbr_printed,
					va_list args, char c);
int				treat_type_x(t_flags *flag, int nbr_printed,
					va_list args, char c);
int				treat_type_xc(t_flags *flag, int nbr_printed,
					va_list args, char c);
int				treat_type_pourcent(t_flags *flag, int nbr_prt, char c);
int				ft_isflags(char c);
int				ft_istype(char c);
void			ft_putchar_fd(char c, int fd);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_realloc(char *str, size_t size);
int				ft_isflags(char c);
int				ft_istype(char c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
void			ft_putnbrbs(unsigned long int nbr, char **str, char *bs,
					int *a);
long long int	ft_atoi_ll(const char *str);
int				ft_write_str(char **str);

#endif
