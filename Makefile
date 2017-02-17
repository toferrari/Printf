# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/14 16:19:10 by tferrari          #+#    #+#              #
#    Updated: 2017/02/17 11:50:27 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

NAME = libftprintf.a

SRC =	ft_call_arg.c \
		ft_convert_signe.c \
		ft_flag_d.c \
		ft_flag_hd.c \
		ft_flag_hhd.c \
		ft_flag_hexa.c \
		ft_flag_lld.c \
		ft_flag_llu.c \
		ft_flag_octal.c \
		ft_flag_pourcent.c \
		ft_flag_str.c \
		ft_flag_chr.c \
		ft_flag_c_null.c \
		ft_flag_u.c \
		ft_flag_p.c \
		ft_parse_flag.c \
		ft_flag_llhexa.c \
		ft_flag_llo.c \
		ft_printf.c

PT_O = $(SRC:.c=.o)

INC = Include/ft_printf.h Libft/libft.h

LFT = Libft/libft.a

all : libft $(NAME)

$(NAME): $(PT_O) $(LFT)
	@ar rcs $(NAME) $(PT_O)

%.o: %.c $(INC)
	@gcc -Wall -Werror -Wextra -Iinclude -ILibft -c $<
	@echo "Fichier" $@ "recompilé."

libft:
	make -C Libft/

clean:
	rm -f $(PT_O)
	make -C Libft clean

fclean: clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re: fclean all
