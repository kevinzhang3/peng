CXX = clang++
CC = clang

CXXFLAGS = -Wall -Iinclude -I/opt/homebrew/include -g -Wextra -std=c++20
CFLAGS = -Wall -Iinclude -I/opt/homebrew/include -g -Wextra

LDFLAGS = -L/opt/homebrew/lib -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

CPPSRCS = src/Sim.cpp
CSRCS = src/glad.c
SRCS = $(CPPSRCS) $(CSRCS)

OBJS = $(CPPSRCS:src/%.cpp=build/%.o) $(CSRCS:src/%.c=build/%.o)

TARGET = sim

all: $(TARGET)

build:
	mkdir -p $@

$(TARGET): $(OBJS) | build
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)

.PHONY: all clean

