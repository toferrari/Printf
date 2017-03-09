# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/14 16:19:10 by tferrari          #+#    #+#              #
#    Updated: 2017/03/09 13:51:13 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_call_arg.c \
		ft_convert_signe.c \
		ft_wchar_to_char.c \
		ft_flag.c \
		ft_flag_d.c \
		ft_flag_hhu.c \
		ft_flag_hho.c \
		ft_flag_hhx.c \
		ft_flag_hd.c \
		ft_flag_ho.c \
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
		ft_flag_wchr.c \
		ft_flag_wstr.c \
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
		Libft/ft_itoa_64.c \
		Libft/ft_itoa.c \
		Libft/ft_itoa_base.c \
		Libft/ft_itoa_base64.c \
		Libft/ft_intlen.c \
		Libft/ft_intlen_64.c \
		Libft/ft_intlen_base.c \
		Libft/ft_intlen_base64.c \
		Libft/ft_putstr.c \
		Libft/ft_bzero.c \
		Libft/ft_strchr.c \
		Libft/ft_strcat.c \
		Libft/ft_strnew.c \
		Libft/ft_memdel.c \
		Libft/ft_isdigit.c \
		Libft/ft_strcpy.c \
		Libft/ft_strlen.c \
		Libft/ft_strncat.c \
		Libft/ft_strlnccat.c \
		Libft/ft_strcat_p.c \
		Libft/ft_realloc_adr_p.c \
		Libft/ft_strupper.c \
		Libft/ft_wchar_len.c \
		Libft/ft_strcpy_p.c \
		Libft/ft_strccat_p.c \
		Libft/ft_wchrcat.c \
		libft/ft_wstr_len.c

PT_O =	ft_call_arg.o \
		ft_convert_signe.o \
		ft_wchar_to_char.o \
		ft_flag.o \
		ft_flag_d.o \
		ft_flag_hhu.o \
		ft_flag_hho.o \
		ft_flag_hhx.o \
		ft_flag_hd.o \
		ft_flag_ho.o \
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
		ft_flag_wchr.o \
		ft_flag_wstr.o \
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
		ft_itoa_64.o \
		ft_itoa.o \
		ft_itoa_base.o \
		ft_itoa_base64.o \
		ft_intlen.o \
		ft_intlen_64.o \
		ft_intlen_base.o \
		ft_intlen_base64.o \
		ft_putstr.o \
		ft_bzero.o \
		ft_strchr.o \
		ft_strcat.o \
		ft_strnew.o \
		ft_memdel.o \
		ft_isdigit.o \
		ft_strcpy.o \
		ft_strlen.o \
		ft_strncat.o \
		ft_strlnccat.o \
		ft_strcat_p.o \
		ft_realloc_adr_p.o \
		ft_strupper.o \
		ft_wchar_len.o \
		ft_strcpy_p.o \
		ft_strccat_p.o \
		ft_wchrcat.o \
		ft_wstr_len.o

all : $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC) -Iinclude
	@ar rc $(NAME) $(PT_O)

clean:
	rm -f $(PT_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
