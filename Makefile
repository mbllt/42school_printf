# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:39:52 by mballet           #+#    #+#              #
#    Updated: 2021/03/17 16:55:48 by mballet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS		= ft_printf.c\
				utils.c\
				utils2.c\
				utils3.c\
				utils4.c\
				utils5.c\
				flag.c\
				treat_flags.c\
				treat_type.c\
				treat_type_c.c\
				treat_type_s.c\
				treat_type_p.c\
				treat_type_d.c\
				treat_type_u.c\
				treat_type_xc.c\
				treat_type_x.c\
				treat_type_pourcent.c\

OBJS 		= $(SRCS:.c=.o)

CC 			= gcc

CFLAGS		= -Wall -Wextra -Werror -I. -c

RM 			= /bin/rm -f

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $?

%.o: %.c	libftprintf.h
			$(CC) $(CFLAGS) $< -o $@

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: clean fclean all re
