CC := gcc
CFLAGS := -Wall -g

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=)

# Default target
all: $(OBJS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: all clean
