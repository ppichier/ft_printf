# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/29 19:18:25 by ppichier     #+#   ##    ##    #+#        #
#   Updated: 2018/02/06 16:03:12 by ppichier    ###    #+. /#+    ###.fr     # #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c ft_type.c ft_unicode.c ft_first_check_format.c \
		ft_tools_check.c ft_parsing.c ft_hexa.c ft_tools_hexa.c \
		ft_string.c ft_char.c ft_iam_d_i.c ft_iam_u.c ft_wchar.c \
		ft_wc.c ft_va_arg_parse.c ft_parse_init.c ft_hexa_unicode_central.c \

HEADERS = ft_printf.h

LIBS = ./libft/libft.a

OBJ = $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "\033[33m"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	libtool -v -static -o $@ $^ $(LIBS) 

$(LIBS):
	make -C libft/

%.o: $(FILES)%.c
	@echo "\033[36m"
	gcc -I $(HEADERS)$(FLAGS) -c $(FILES)

clean:
	@echo "\033[31m"
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	@echo "\033[31m"
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
