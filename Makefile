.PHONY: all clean fclean re

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
B_NAME = so_long_bonus

CFILES = Mandatory/main.c\
		 Mandatory/parsing.c\
		 Mandatory/parsing_utils.c\
		 Mandatory/utils.c\
		 Mandatory/get_next_line.c\
		 Mandatory/get_next_line_utils.c\
		 Mandatory/error_handle.c\
		 Mandatory/free_handle.c\
		 Mandatory/moves.c\
		 Mandatory/draw_image.c\
		 Mandatory/ft_printf.c\
		 Mandatory/ft_toolsbase.c

BFILES = Bonus/main.c\
		 Bonus/parsing_bonus.c\
		 Bonus/parsing_utils_bonus.c\
		 Bonus/utils_bonus.c\
		 Bonus/animation_bonus.c\
		 Bonus/get_next_line.c\
		 Bonus/get_next_line_utils.c\
		 Bonus/error_handle_bonus.c\
		 Bonus/free_handle_bonus.c\
		 Bonus/moves_bonus.c\
		 Bonus/draw_image_bonus.c

OBJ = $(patsubst %.c, %.o, $(CFILES))
B_OBJ = $(patsubst %.c, %.o, $(BFILES))

all: lib $(NAME)

lib:
	@make -C libft

$(OBJ): %.o: %.c Mandatory/so_long.h
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME) : libft/libft.a $(OBJ) Mandatory/so_long.h
	@$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)
	@echo making ... Done.

bonus : lib $(B_NAME)

$(B_OBJ): %.o: %.c Bonus/so_long_bonus.h
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(B_NAME) : libft/libft.a $(B_OBJ) Bonus/so_long_bonus.h
	@$(CC) $(FLAGS) $(B_OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(B_NAME)
	@echo making bonus... Done.

clean:
	@$(RM) $(OBJ) $(B_OBJ)
	@make -C libft clean
	@echo cleaning ... Done.

fclean: clean
	@$(RM) $(NAME) $(B_NAME)
	@make -C libft fclean

re: fclean all