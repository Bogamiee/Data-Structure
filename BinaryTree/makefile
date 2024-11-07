# 컴파일러 설정
CC = gcc
CFLAGS = -Wall -g

# 파일 설정
SRCS = main.c BinaryTree.c Stack.c Queue.c
OBJS = $(SRCS:.c=.o)
DEPS = BinaryTree.h Stack.h Queue.h
TARGET = main

# 최종 실행 파일
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 개별 소스 파일 컴파일
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# 정리
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
	clear
