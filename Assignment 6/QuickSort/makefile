# 컴파일러와 플래그 설정
CC = g++
CFLAGS = -Wall -g -std=c++17
LDFLAGS = -lm

# 실행 파일 이름
TARGET = main.exe

# 소스 파일 목록
SRCS = DataGen.cpp QuickSort.cpp TimeMsr.cpp main.cpp

# 오브젝트 파일 목록
OBJS = $(SRCS:.cpp=.o)

# 헤더 파일 목록
DEPS = DataGen.h QuickSort.h TimeMsr.h

# 기본 규칙
all: $(TARGET)

# 타겟 생성 규칙
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# 개별 오브젝트 파일 생성 규칙
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# 클린 규칙 (Linux/Windows 대응)
clean:
ifeq ($(OS),Windows_NT)
	del /Q *.o $(TARGET)
else
	rm -f $(OBJS) $(TARGET)
	clear
endif

# 임시 파일 삭제 규칙
cleanall: clean
ifeq ($(OS),Windows_NT)
	del /Q *~ *.bak
else
	rm -f *~ *.bak
endif
