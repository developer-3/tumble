CXX = clang++
CXXFLAGS = -Wall -fPIC
SRC := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
LDFLAGS := -shared
LDLIBS :=
OBJFILES := $(SRC:.cpp=.o)
TARGET = lib/libtumble.so

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -f $(OBJFILES) $(TARGET) *~
