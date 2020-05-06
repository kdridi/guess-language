CC = clang -fsanitize=address -fno-omit-frame-pointer
CFLAGS = -W -Wall -Wextra
RM = rm -f

SRC = main.c
OBJ = $(SRC:.c=.o)
TARGET = main

all: $(TARGET)
	./$^

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re