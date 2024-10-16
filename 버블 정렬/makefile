# Makefile for Bubble Sort project with TimeMsr for Windows

# 변수 정의
CXX = g++
CXXFLAGS = -Wall -g
TARGET = bubblesort.exe
SOURCES = main.cpp BubbleSort.cpp TimeMsr.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# 기본 타겟
all: $(TARGET)

# 링크 단계
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

# 컴파일 단계
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 클린 타겟
clean:
	del $(OBJECTS) $(TARGET)

# 테스트 타겟
test: $(TARGET)
	$(TARGET)

.PHONY: all clean test
