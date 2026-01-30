CC = gcc
CFLAGS = -Wall -Wextra -I./src
OBJ = src/main.o src/finance.o src/utils.o

SimulatorInvestitiiFinanciare: $(OBJ)
	$(CC) -o SimulatorInvestitiiFinanciare $(OBJ) -lm

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o SimulatorInvestitiiFinanciare