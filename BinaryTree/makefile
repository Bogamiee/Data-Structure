# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g
OBJDIR = obj

# Source and header files
SRCS = Calc.c Queue.c Stack.c Tree.c main.c
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
HEADERS = Calc.h Queue.h Stack.h Tree.h

# Target executable
TARGET = main

# Default target
all: $(TARGET)

# Linking object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule for compiling .c files into .o files
$(OBJDIR)/%.o: %.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean build files
clean:
	rm -rf $(OBJDIR) $(TARGET)
	clear

# Phony targets
.PHONY: all clean

