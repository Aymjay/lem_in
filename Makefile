NAME =	lem-in

SRC =	main.c\
		tube_count.c\
		tab_func.c\
		struc.c\
		resolve.c\
		print_list.c\
		parsing_tubes.c\
		parsing_rooms.c\
		other_way.c\
		list.c\
		checking.c\
		ant_sending.c\
		lem_in.c\
		check_isroom.c\
		struc_second.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft
	gcc -o $(NAME) $(OBJ) -L libft -lft

%.o: %.c libft/libft.h
	gcc -c $(GCCF) -I libft $< -o $@

.PHONY: clean fclean re

clean:
	make -C libft fclean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all