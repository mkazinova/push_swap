NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra -c

RM = /bin/rm -f

SRCFILES = $(shell find . -name "*.c")
OBJECTS = $(patsubst %.c,%.o,$(shell find . -name "*.c" -exec basename {} \;))

INCLUDE_PATH = -I./includes


$(NAME): $(shell find . -name "*.c")
	@$(CC) $(CFLAGS) $(INCLUDE_PATH) $(SRCFILES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
