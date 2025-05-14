# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Iincludes -g -Wextra -std=c++20  

# Source and object files
SRCS = Sim.cpp
OBJS = build/Sim.o

# Output binary
TARGET = sim

# Default target
all: $(TARGET)

build:
	mkdir -p $@

# Link the object files into the final binary
$(TARGET): $(OBJS) | build
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
build/%.o: %.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf build $(TARGET)

.PHONY: all clean

