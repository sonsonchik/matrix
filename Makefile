CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -I./src
TARGET = matrix_calc
TEST_TARGET = matrix_test

SRC = src/matrix.cpp src/main.cpp
TEST_SRC = src/matrix.cpp src/test.cpp

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

$(TEST_TARGET): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean