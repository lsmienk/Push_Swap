# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmienk <lsmienk@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/15 12:17:27 by lsmienk        #+#    #+#                 #
#    Updated: 2020/01/03 15:29:10 by lsmienk       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
SRC1 = push_swap is_sorted push rev_rotate get_medium swap rotate \
	print_stack partition_sort_a partition_sort_b push_b_top set_min_max \
	small_sort sort_three push_top initial_devide sort_three_rev is_rev_sorted \
	free_set create_stack small_b_stack short_stack_sort ret_sorted_bstack \
	init_stacks
SRC2 = checker is_sorted check_swap rotate rev_rotate push create_stack \
	free_set set_min_max print_stack init_stacks
SRCF1 = $(SRC1:%=%.c)
OBJ1 = $(SRC1:%=%.o)
SRCF2 = $(SRC2:%=%.c)
OBJ2 = $(SRC2:%=%.o)
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

MAKECOLOUR = \033[38;5;208m
CLEANCOLOUR = \033[38;5;229m
FCLEANCOLOUR = \033[38;5;214m
LIBCOLOUR = \033[38;5;220m
RESETCOLOUR = \033[0m

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCF1)
	@echo "$(LIBCOLOUR)Compiling Libraries$(RESETCOLOUR)"
	@make -C libft/
	@echo "$(MAKECOLOUR)Compiling Push_swap$(RESETCOLOUR)"
	@clang $(FLAGS) -I libft/includes -c $(SRCF1)
	@clang -o $(NAME1) $(OBJ1) $(LIBFT)

$(NAME2): $(SRCF2)
	@echo "$(MAKECOLOUR)Compiling checker$(RESETCOLOUR)"
	@clang $(FLAGS) -I libft/includes -c $(SRCF2)
	@clang -o $(NAME2) $(OBJ2) $(LIBFT)
clean:
	@echo "$(CLEANCOLOUR)Cleaning Libraries$(RESETCOLOUR)"
	@make -C libft/ clean
	@rm -f $(OBJ1) $(OBJ2)

fclean: clean
	@echo "$(FCLEANCOLOUR)clean Libraries and $(NAME1) $(NAME2) $(RESETCOLOUR)"
	@make -C libft/ fclean
	@rm -f $(NAME1) $(NAME2)

re: fclean all
