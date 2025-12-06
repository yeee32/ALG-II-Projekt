CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O3

SRC = main.cpp bst.cpp avl.cpp opt.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = trees

# Default rule
all: $(TARGET)

# Link the program
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile each .cpp file into .o (automatic)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean