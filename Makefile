CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

FLAGS = -Wall -Wextra -Werror

INC_DIR = ./libft/includes
OBJ_DIR = ./obj/
LIB_DIR = ./libft/

CH_SRC = checker.c get_next_line_single_fd.c perform_command.c
CH_OBJ = $(addprefix $(OBJ_DIR),$(CH_OBJ_NAMES))
CH_OBJ_NAMES = $(CH_SRC:.c=.o)

PS_SRC = push_swap_for_small_stack.c push_swap_main.c quicksort_left.c quicksort_right.c \
		push_swap_median.c optimisation.c
PS_OBJ = $(addprefix $(OBJ_DIR),$(PS_OBJ_NAMES))
PS_OBJ_NAMES = $(PS_SRC:.c=.o)

COMMON_SRC = push.c swap_stack_top.c rotate_stack.c clear_stacks.c build_stacks.c \
		ft_atol.c is_sorted.c initialize_empty_stack.c get_debug_mode.c \
		string_array_helpers.c
COMMON_OBJ = $(addprefix $(OBJ_DIR),$(COMMON_OBJ_NAMES))
COMMON_OBJ_NAMES = $(COMMON_SRC:.c=.o)

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CH_OBJ) $(COMMON_OBJ)
	make -C $(LIB_DIR)
	gcc $(FLAGS) -o $(CHECKER_NAME) $(COMMON_OBJ) $(CH_OBJ) -lm -L $(LIB_DIR) -lft

$(PUSH_SWAP_NAME): $(PS_OBJ) $(COMMON_OBJ)
	make -C $(LIB_DIR)
	gcc $(FLAGS) -o $(PUSH_SWAP_NAME) $(COMMON_OBJ) $(PS_OBJ) -lm -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(CHECKER_NAME)
	rm -f $(PUSH_SWAP_NAME)

re: fclean all
