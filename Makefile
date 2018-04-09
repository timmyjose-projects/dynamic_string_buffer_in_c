CC = gcc
CFLAGS = -Wall -Wextra

SRCS = dyn_str_buf.c error.c main.c
OBJS = dyn_str_buf.o error.o main.o
TARGET = main

build: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.c.o: %.c
	$(CC) -c $(SRCS) $< -o $@

clean:
	rm -rf *.o
	rm -rf $(TARGET)
