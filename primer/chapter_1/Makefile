CXX := clang++
CPPFLAGS = -I../include
CXXFLAGS =
LDFLAGS =

SRC=$(wildcard *.cpp)
OBJECTS=$(SRC:%.cpp=%.o)
TARGET = $(SRC:%.cpp=%)

all: $(TARGET)


.PHONY: clean all
clean:
	rm -rf $(OBJECTS)
	rm -rf $(TARGET)
	rm -rf foo bar
