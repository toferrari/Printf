# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 15:34:20 by tferrari          #+#    #+#              #
#    Updated: 2017/03/28 18:07:21 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src

SRC_FILE =	ft_call_arg.c ft_convert_signe.c ft_flag.c ft_flag_b.c \
			ft_flag_c_null.c ft_flag_chr.c ft_flag_d.c ft_flag_hd.c \
			ft_flag_hexa.c ft_flag_hhd.c ft_flag_hho.c ft_flag_hhu.c \
			ft_flag_hhx.c ft_flag_ho.c ft_flag_lld.c ft_flag_llhexa.c \
			ft_flag_llo.c ft_flag_llu.c ft_flag_octal.c ft_flag_p.c \
			ft_flag_pourcent.c ft_flag_str.c ft_flag_u.c ft_flag_wchr.c \
			ft_flag_wstr.c ft_parse_flag.c ft_printf.c ft_wchar_to_char.c \
			ft_wstr_len.c ft_strcpy_p.c ft_strccat_p.c ft_wchrcat.c \
			ft_wchar_len.c ft_strupper.c ft_intlen_base64.c ft_itoa_base64.c \
			ft_intlen_base.c ft_itoa_base.c ft_realloc_adr_p.c ft_strcat_p.c \
			ft_itoa_64.c ft_intlen_64.c ft_strclen.c ft_intlen_64.c \
			ft_itoa_64.c ft_bzero.c ft_intlen.c ft_isdigit.c ft_memdel.c \
			ft_putchar.c ft_putstr.c ft_putstrnbr.c ft_strcat.c ft_strchr.c \
			ft_strcpy.c ft_strlen.c ft_strlnccat.c ft_strncat.c ft_strnccat.c \
			ft_strnew.c ft_putnbr.c


SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.c=.o))

INC = Libft/libft.h Include/ft_printf.h

all : $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Compilation de libftprintf.a OK"

libft: $(LFT)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@gcc -Wall -Werror -Wextra -IInclude -ILibft -c -o $@ $<
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Fichier objet de printf supprimé"

fclean: clean
	@rm -f $(NAME)
	@echo ".a supprimé"

re: fclean all
