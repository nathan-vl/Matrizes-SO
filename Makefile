CC = g++
CFLAGS = -Iinclude -O3 -Wall -Wextra
SRC=`find . -name "*.cpp"`

Matriz:
	$(CC) $(CFLAGS) -o $@ $(SRC)
