# 컴파일러 설정
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# 디렉토리 설정
BUILD_DIR = build
SRC_FILES = Queue.c Node.c Huffman.c main.c
HEADER_FILES = Queue.h Node.h Huffman.h
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TARGET = main

# 기본 규칙
all: $(TARGET)

# 실행 파일 규칙
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES)

# 객체 파일 규칙
$(BUILD_DIR)/%.o: %.c $(HEADER_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 클린 규칙
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	clear

# 의존성 관리
.PHONY: all clean
