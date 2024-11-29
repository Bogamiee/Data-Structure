CXX = g++

OBJ_DIR = build
TARGET = main

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	clear
