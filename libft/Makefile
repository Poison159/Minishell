# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmakse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/13 08:34:33 by tmaske            #+#    #+#              #
#    Updated: 2016/11/07 09:52:44 by tmaske           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_puterror.c \
ft_puterror_fd.c ft_putnendl.c ft_putnendl_fd.c ft_strsplitnum.c ft_atoi_max.c \
get_next_line.c ft_print_rep.c ft_iarrset.c ft_iarrbig_pos.c ft_iarrsml_pos.c \
ft_iarrbig.c ft_iarrsml.c ft_isdigit_str.c ft_arrdel.c  ft_arrlen.c ft_chrpos.c\
ft_arrprint.c

OBJ = $(SRC:.c=.o)

HEADER = ./libft.h

FLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc libft.a $(OBJ) $(HEADER)
	@ranlib libft.a
	@echo "Libft Compiled"

clean:
	@rm -f $(OBJ)
	@echo "Libft Cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "Libft FCleaned"

mclean:
	@find . -name '._*' -type f -delete
	@echo "Removed hidden ._ files."

re: fclean all

norm:
	@echo "Basic Memory Functions"
	@norminette ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c
	@echo "\nBasic String Functions"
	@norminette ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c
	@echo "\nOther Basic Functions"
	@norminette ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c
	@echo "\nAdditional Memory Functions"
	@norminette ft_memalloc.c ft_memdel.c
	@echo "\nAdditional String Functions"
	@norminette ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c
	@echo "\nOther Additional Functions"
	@norminette ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
	@echo "\nBonus List Functions"
	@norminette ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
	@echo "\nExtra Functions"
	@norminette ft_puterror.c ft_puterror_fd.c ft_putnendl.c ft_putnendl_fd.c ft_strsplitnum.c ft_atoi_max.c get_next_line.c ft_print_rep.c ft_iarrset.c ft_iarrbig_pos.c ft_iarrsml_pos.c ft_iarrbig.c ft_iarrsml.c ft_isdigit_str.c ft_arrdel.c ft_arrlen.c ft_chrpos.c ft_arrprint.c
