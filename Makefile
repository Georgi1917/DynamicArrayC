CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main.exe

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	del $(TARGET)