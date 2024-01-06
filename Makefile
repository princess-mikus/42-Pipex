NAME 	:=	pipex
FILES	:=	utils	\
			here_doc

LIBFT	:= libft.a
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
OBJ_DIR	:=	obj
FSRC	:= $(addsuffix .c, $(FILES))
MSRC	:= $(addsuffix .c, $(NAME))
BSRC	:= $(addsuffix _bonus.c, $(NAME))
FOBJ	:=	$(FSRC:%.c=$(OBJ_DIR)/%.o)
BOBJ	:=	$(BSRC:%.c=$(OBJ_DIR)/%.o)
MOBJ	:=	$(MSRC:%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(OBJ_DIR):
	@mkdir obj

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Compiling LIBFT..."
	@make -C libft/ && mv libft/$(LIBFT) $(LIBFT) >/dev/null
	@echo "LIBFT Compiled!"

$(NAME): $(FOBJ) $(MOBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(MOBJ) $(FOBJ) $(LIBFT) -o $(NAME)
	@echo "Mandatory compiled!"

bonus: $(FOBJ) $(BOBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(BOBJ) $(FOBJ) $(LIBFT) -o $(NAME)
	@echo "Bonus compiled!"

clean:
	@make -C libft clean >/dev/null
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: fclean all