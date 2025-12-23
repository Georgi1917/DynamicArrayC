CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main.exe

SRC = main.c implementation/d_string_arr.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	del $(TARGET)