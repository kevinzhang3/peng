# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Iinclude -g -Wextra -std=c++20  

# Source and object files
SRCS = src/Sim.cpp
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
build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf build $(TARGET)

.PHONY: all clean

