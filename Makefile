CC = gcc
CFLAGS = -Wall -Wextra -I./src
OBJ = src/main.o src/finance.o src/utils.o

investment_sim: $(OBJ)
	$(CC) -o investment_sim $(OBJ) -lm

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o investment_sim