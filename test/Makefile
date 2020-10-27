CPP=g++
CPPFLAGS=-I. -std=c++11 -ldl -pthread
DEPS = Test.h MediaService.h
OBJ = Test.o

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

TARGET = encodertest

all: $(TARGET)

clean: 
	rm -f $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	$(CPP) -o $@ $^ $(CPPFLAGS)
