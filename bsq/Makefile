CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/map.c src/solve.c src/print.c src/error.c
OBJ = $(SRC:.c=.o)
TARGET = bsq

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean