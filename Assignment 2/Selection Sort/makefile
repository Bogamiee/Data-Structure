# Makefile
CC = g++
CFLAGS = -Wall -g

# 소스 파일 목록
SRC = InsertionSorter.cpp TimeMsr.cpp main.cpp
# .o 파일 목록을 자동 생성
OBJ = $(SRC:.cpp=.o)

PROG = main  # 최종 실행 파일 이름

# 기본 타겟
all: $(PROG)

# 실행 파일을 생성하는 규칙
$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

# .o 파일을 생성하는 규칙
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# clean 명령으로 객체 파일과 실행 파일 삭제
clean:
	del /Q $(OBJ) $(PROG)
