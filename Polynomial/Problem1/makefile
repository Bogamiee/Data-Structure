# 컴파일러와 플래그 설정
CC = g++
CFLAGS = -Wall -g
LDFLAGS = 

# 타겟 실행 파일 이름
TARGET = main

# 소스 파일과 헤더 파일
SRCS = main.cpp polynomial.cpp
DEPS = polynomial.h Term.h

# 오브젝트 파일 목록 (SRCS의 확장자를 .cpp에서 .o로 변경)
OBJS = $(SRCS:.cpp=.o)

# 기본 빌드 타겟
all: $(TARGET)

# 실행 파일 빌드
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# 개별 오브젝트 파일 빌드
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# 빌드 파일 제거
clean:
	rm -f $(OBJS) $(TARGET)
	clear

# 빌드 파일 및 임시 파일 제거
cleanall: clean
	rm -f *~ *.bak
	clear
