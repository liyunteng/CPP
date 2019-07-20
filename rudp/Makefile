CXX = clang++
CPPFLAGS = -I.
CXXFLAGS = -Wall -ggdb -fPIC
LDFLAGS = -L. -Wl,-rpath=.

EXE_SRC = test.cpp
LIB_SRC=$(filter-out $(EXE_SRC), $(wildcard *.cpp))
LIB_OBJ=$(LIB_SRC:%.cpp=%.o)
EXE_OBJ=$(EXE_SRC:%.cpp=%.o)

EXE_TARGET = test
LIB_TARGET = librudp.so
TARGET = $(EXE_TARGET) $(LIB_TARGET)

all: $(LIB_TARGET) $(EXE_TARGET)

$(EXE_TARGET): $(EXE_OBJ)
	$(CXX) -o $(EXE_TARGET) $(LDFLAGS) $< -lrudp

$(LIB_TARGET): $(LIB_OBJ)
	$(CXX) -o $(LIB_TARGET) -shared  $(LDFLAGS) $<

%.o : %.cpp
	$(CXX) -o $@ -c $(CXXFLAGS) $(CPPFLAGS) $<

clean:
	@echo "cleaning ..."
	@rm -rf $(LIB_OBJ) $(EXE_OBJ) $(TARGET)
