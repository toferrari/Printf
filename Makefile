# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/14 16:19:10 by tferrari          #+#    #+#              #
#    Updated: 2017/02/21 18:58:49 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_call_arg.c \
		ft_convert_signe.c \
		ft_flag_d.c \
		ft_flag_hh.c \
		ft_flag_hhu.c \
		ft_flag_hho.c \
		ft_flag_hhx.c \
		ft_flag_hd.c \
		ft_flag_hexa.c \
		ft_flag_lld.c \
		ft_flag_llu.c \
		ft_flag_octal.c \
		ft_flag_pourcent.c \
		ft_flag_str.c \
		ft_flag_u.c \
		ft_parse_flag.c \
		ft_flag_llhexa.c \
		ft_flag_c_null.c \
		ft_flag_chr.c \
		ft_flag_hhd.c \
		ft_flag_llo.c \
		ft_flag_p.c \
		ft_printf.c \
		Libft/ft_realloc_chr.c \
		Libft/ft_realloc_adr.c \
		Libft/ft_strclen.c \
		Libft/ft_strccat.c \
		Libft/ft_strnchr.c \
		Libft/ft_strputnchr.c \
		Libft/ft_strnccat.c \
		Libft/ft_intlen_intmax.c \
		Libft/ft_intlen_uintmax.c \
		Libft/ft_itoa_64.c \
		Libft/ft_itoa_u64.c \
		Libft/ft_itoa_u.c \
		Libft/ft_intlen_u.c \
		Libft/ft_intlen_o.c \
		Libft/ft_itoa_o.c \
		Libft/ft_intlen_h.c \
		Libft/ft_itoa_h.c \
		Libft/ft_itoa.c \
		Libft/ft_intlen.c \
		Libft/ft_putstr.c \
		Libft/ft_bzero.c \
		Libft/ft_strchr.c \
		Libft/ft_strcat.c \
		Libft/ft_strnew.c \
		Libft/ft_memdel.c \
		Libft/ft_isdigit.c \
		Libft/ft_strcpy.c \
		Libft/ft_strlen.c \
		Libft/ft_itoa_llh.c \
		Libft/ft_intlen_llh.c \
		Libft/ft_strncat.c \
		Libft/ft_intlen_llo.c \
		Libft/ft_itoa_llo.c \
		Libft/ft_strlnccat.c \
		Libft/ft_strcat_p.c \
		Libft/ft_realloc_adr_p.c

PT_O =	ft_call_arg.o \
		ft_convert_signe.o \
		ft_flag_d.o \
		ft_flag_hh.o \
		ft_flag_hhu.o \
		ft_flag_hho.o \
		ft_flag_hhx.o \
		ft_flag_hd.o \
		ft_flag_hexa.o \
		ft_flag_lld.o \
		ft_flag_llu.o \
		ft_flag_octal.o \
		ft_flag_pourcent.o \
		ft_flag_str.o \
		ft_flag_u.o \
		ft_parse_flag.o \
		ft_flag_llhexa.o \
		ft_flag_c_null.o \
		ft_flag_chr.o \
		ft_flag_hhd.o \
		ft_flag_llo.o \
		ft_flag_p.o \
		ft_printf.o \
		ft_realloc_chr.o \
		ft_realloc_adr.o \
		ft_strclen.o \
		ft_strccat.o \
		ft_strnchr.o \
		ft_strputnchr.o \
		ft_strnccat.o \
		ft_intlen_intmax.o \
		ft_intlen_uintmax.o \
		ft_itoa_64.o \
		ft_itoa_u64.o \
		ft_itoa_u.o \
		ft_intlen_u.o \
		ft_intlen_o.o \
		ft_itoa_o.o \
		ft_intlen_h.o \
		ft_itoa_h.o \
		ft_itoa.o \
		ft_intlen.o \
		ft_putstr.o \
		ft_bzero.o \
		ft_strchr.o \
		ft_strcat.o \
		ft_strnew.o \
		ft_memdel.o \
		ft_isdigit.o \
		ft_strcpy.o \
		ft_strlen.o \
		ft_itoa_llh.o \
		ft_intlen_llh.o \
		ft_strncat.o \
		ft_intlen_llo.o \
		ft_itoa_llo.o \
		ft_strlnccat.o \
		ft_strcat_p.o \
		ft_realloc_adr_p.o

all : $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC) -Iinclude
	@ar rc $(NAME) $(PT_O)

clean:
	rm -f $(PT_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
