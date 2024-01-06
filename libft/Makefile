# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikus <mikus@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 11:53:01 by fcasaubo          #+#    #+#              #
#    Updated: 2023/12/27 17:07:47 by mikus            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= libft.a
SRC 	:=				\
	ft_isalpha.c		\
	ft_isdigit.c		\
	ft_isalnum.c		\
	ft_isascii.c		\
	ft_isprint.c		\
	ft_strlen.c			\
	ft_memset.c			\
	ft_bzero.c			\
	ft_memcpy.c			\
	ft_memmove.c		\
	ft_strlcpy.c		\
	ft_strlcat.c		\
	ft_toupper.c		\
	ft_tolower.c		\
	ft_strchr.c			\
	ft_strrchr.c		\
	ft_strncmp.c		\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_strnstr.c		\
	ft_atoi.c			\
	ft_calloc.c			\
	ft_strdup.c			\
	ft_substr.c			\
	ft_strjoin.c		\
	ft_strtrim.c		\
	ft_split.c			\
	ft_itoa.c			\
	ft_strmapi.c		\
	ft_striteri.c		\
	ft_putchar_fd.c		\
	ft_putstr_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_putnbrpf_fd.c	\
	ft_printf.c			\
	ft_putnbr_hex_fd.c	\
	ft_putnbru_fd.c 	\
	ft_putaddress_fd.c	\
	ft_write_character.c\
	ft_write_string.c	\
	ft_write_address.c	\
	ft_write_number.c	\
	ft_write_unsigned.c	\
	ft_write_hex.c		\
	get_next_line.c		\
	get_next_line_utils.c
BSRC	:=				\
	ft_lstnew.c			\
	ft_lstadd_front.c	\
	ft_lstsize.c		\
	ft_lstlast.c		\
	ft_lstadd_back.c	\
	ft_lstdelone.c		\
	ft_lstclear.c		\
	ft_lstiter.c		\
	ft_lstmap.c

OBJ		:= $(SRC:.c=.o)
BOBJ	:= $(BSRC:.c=.o)

GCC		:= gcc

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	ar -cr $(NAME) $(OBJ)

bonus: $(BOBJ)
	ar -cr $(NAME) $(BOBJ)

%.o: %.c
	$(GCC) -c *.c

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re