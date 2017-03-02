NAME =	libft.a

SRC =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_intlen.c ft_reverse_nb.c \
		ft_nbword.c ft_nbletter.c ft_fill.c ft_putstrnbr.c ft_putnbrendl.c \
		ft_realloc_chr.c ft_realloc_adr.c ft_strclen.c ft_strccat.c \
		ft_strnchr.c ft_strputnchr.c ft_strnccat.c ft_intlen_64.c ft_itoa_64.c \
		ft_strlnccat.c ft_strcat_p.c ft_realloc_adr_p.c ft_intlen_base.c \
		ft_itoa_base.c ft_intlen_base64.c ft_itoa_base64.c ft_strupper.c \
		ft_wchar_len.c ft_wchrcat.c ft_strccat_p.c ft_strcpy_p.c ft_wstr_len.c

PT_O =	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(INC)
	@gcc -Wall -Werror -Wextra -IInclude -c $<
	@echo "Fichier" $@ "recompilé."

$(NAME): $(PT_O)
	@ar rc $(NAME) $(PT_O)
	@echo "compiler"

clean:
	@rm -f $(PT_O)
	@echo "Fichier obj efface"

fclean: clean
	@rm -f $(NAME)
	@echo "Fichier obj efface"
	@echo "Lift efface"

re: fclean all
