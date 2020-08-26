CC = g++
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

TARGET = password_cracker
SRC_EXT = cc

SRC := $(wildcard *.$(SRC_EXT))
OBJ := $(patsubst ./%,./%,$(SRC:.$(SRC_EXT)=.o))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $^

%.o: $(SRC_EXT)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.o password_cracker dictionary brute_force random

-include $(patsubst ./%,./%,$(SRC:.$(SRC_EXT)=.d))
