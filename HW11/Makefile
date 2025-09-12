CC = gcc
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror

SRCS = main.c hw11.c
OBJS = $(SRCS:.c=.o)

hw11: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hw11

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@