# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2

# Directories
BUILD_DIR = build
SRC_DIR = .
TARGET = main

# Source and object files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/Huffman.c $(SRC_DIR)/Queue.c $(SRC_DIR)/Tree.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# OS detection
ifeq ($(OS),Windows_NT)
    RM = del /F /Q
    EXE = $(TARGET).exe
else
    RM = rm -f
    EXE = $(TARGET)
endif

# Default target
all: $(BUILD_DIR) $(EXE)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files to create the executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	$(RM) $(BUILD_DIR)/* $(EXE)
	clear

# Rebuild target
rebuild: clean all

# Include header dependencies
$(BUILD_DIR)/Huffman.o: $(SRC_DIR)/Huffman.c $(SRC_DIR)/Huffman.h
$(BUILD_DIR)/Queue.o: $(SRC_DIR)/Queue.c $(SRC_DIR)/Queue.h
$(BUILD_DIR)/Tree.o: $(SRC_DIR)/Tree.c $(SRC_DIR)/Tree.h
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/Huffman.h $(SRC_DIR)/Queue.h $(SRC_DIR)/Tree.h

