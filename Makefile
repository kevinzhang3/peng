# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Iinclude -I/opt/homebrew/include -g -Wextra -std=c++20  
LDFLAGS = -L/opt/homebrew/lib -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl 

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
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf build $(TARGET)

.PHONY: all clean

