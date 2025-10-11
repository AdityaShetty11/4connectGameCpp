CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Iinclude

TARGET := connect4
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run clean
