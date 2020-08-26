CXX = g++
CXXFLAGS = -g -Wall -std=c++17

TARGET = nums
SRC_EXT = cc

CPPFLAGS = -Iinclude
LDFLAGS =

SRC := $(wildcard *.$(SRC_EXT))
OBJ := $(patsubst ./%,./%,$(SRC:.$(SRC_EXT)=.o))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) -o $(TARGET) $^

%.o: $(SRC_EXT)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf *.o $(TARGET)

-include $(patsubst ./%,./%,$(SRC:.$(SRC_EXT)=.d))
