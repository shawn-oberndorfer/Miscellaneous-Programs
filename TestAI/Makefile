# Makefile for Ore Refining Calculator

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Executable name
TARGET = orecalc

# Source files
SRCS = main.cpp Ore.cpp Refinery.cpp OreValues.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the program
$(Target): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
# Rule to build .o files from .cpp
%.o %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
# Clean up build artifacts
clean: 
	rm -f $(OBJS) $(TARGET)