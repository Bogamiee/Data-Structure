CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

TARGET = main

SRCS = main.c matrix.c sparse.c timer.c

OBJS = $(SRCS:.c=.o)

DEPS = matrix.h sparse.h timer.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	clear

cleanall: clean
	rm -f *~ *.bak
