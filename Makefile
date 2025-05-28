CXX = clang++
CC = clang
OS = $(shell uname)

CXXFLAGS = -Wall -Iinclude -I/opt/homebrew/include -Iextern -g -Wextra -std=c++20
CFLAGS = -Wall -Iinclude -I/opt/homebrew/include -Iextern -g -Wextra

ifeq ($(OS),Linux)
LDFLAGS = -L/opt/homebrew/lib -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
else
LDFLAGS = -L/opt/homebrew/lib -lglfw -lX11 -lpthread -lXrandr -lXi -ldl -framework OpenGL
endif

CPPSRCS = src/Sim.cpp src/Body.cpp
ENGINE_CPPSRCS = src/Engine.cpp src/Body.cpp
CSRCS = extern/glad.c

SRCS = $(CPPSRCS) $(CSRCS)

OBJS = $(CPPSRCS:src/%.cpp=build/%.o) build/glad.o
ENGINE_OBJS = $(ENGINE_CPPSRCS:src/%.cpp=build/%.o) build/glad.o

TARGET = run
ENGINE_TARGET = eng

all: $(TARGET)

build:
	mkdir -p $@

$(TARGET): $(OBJS) | build
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(ENGINE_TARGET): $(ENGINE_OBJS) | build
	$(CXX) $(CXXFLAGS) $(ENGINE_OBJS) $(LDFLAGS) -o $@

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/glad.o: extern/glad.c | build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET) $(ENGINE_TARGET)

.PHONY: all clean engine

engine: $(ENGINE_TARGET)

