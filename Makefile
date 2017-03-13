# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 15:34:20 by tferrari          #+#    #+#              #
#    Updated: 2017/03/13 15:47:58 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src

SRC_FILE =	ft_call_arg.c ft_convert_signe.c ft_wchar_to_char.c ft_flag.c \
			ft_flag_d.c ft_flag_hhu.c ft_flag_hho.c ft_flag_hhx.c ft_flag_hd.c \
			ft_flag_ho.c ft_flag_hexa.c ft_flag_lld.c ft_flag_llu.c \
			ft_flag_octal.c ft_flag_pourcent.c ft_flag_str.c ft_flag_u.c \
			ft_parse_flag.c ft_flag_llhexa.c ft_flag_c_null.c ft_flag_chr.c \
			ft_flag_wchr.c ft_flag_wstr.c ft_flag_hhd.c ft_flag_llo.c \
			ft_flag_p.c ft_printf.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.c=.o))

INC = Libft/libft.h Include/ft_printf.h

LFT = Libft/libft.a

all : $(NAME)

$(NAME): $(LFT) $(OBJS)
	@cp $(LFT) $(NAME)
	@ar rcs $(NAME) $@ $(OBJS)
	@echo "Compilation de libftprintf.a OK"

libft: $(LFT)

$(LFT):
	make -C Libft/

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@gcc -Wall -Werror -Wextra -IInclude -ILibft -c -o $@ $<
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@make -C Libft clean
	@echo "Fichier objet de printf supprimé"

fclean: clean
	@rm -f $(NAME)
	@rm -f Libft/libft.a
	@echo ".a supprimé"

re: fclean all
