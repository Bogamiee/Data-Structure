# Makefile

CC = g++
CFLAGS = -Wall -g
SRC = Matrix.cpp MatrixCalc.cpp MatrixOperation.cpp TimeMsr.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
PROG = main

# 기본 타겟: 실행 파일 생성
all: $(PROG)

# 실행 파일 생성 규칙
$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

# .cpp 파일에서 .o 파일 생성 규칙 (자동화)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# clean 타겟: 생성된 파일 삭제
clean:
	rm -f $(OBJ) $(PROG)
