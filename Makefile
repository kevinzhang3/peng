CXX = clang++
CC = clang

CXXFLAGS = -Wall -Iinclude -I/opt/homebrew/include -Iextern -g -Wextra -std=c++20
CFLAGS = -Wall -Iinclude -I/opt/homebrew/include -Iextern -g -Wextra

LDFLAGS = -L/opt/homebrew/lib -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

CPPSRCS = src/Sim.cpp
CSRCS = extern/glad.c
SRCS = $(CPPSRCS) $(CSRCS)

OBJS = $(CPPSRCS:src/%.cpp=build/%.o) build/glad.o

TARGET = run

all: $(TARGET)

build:
	mkdir -p $@

$(TARGET): $(OBJS) | build
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/glad.o: extern/glad.c | build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)

.PHONY: all clean

