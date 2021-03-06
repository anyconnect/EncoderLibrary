SHELL = /bin/sh
.PHONY: clean

CC= g++
CPPFLAGS= -fPIC -g
LDFLAGS= -shared

SOURCES = $(shell echo *.cpp)
HEADERS = $(shell echo *.h)
OBJECTS=$(SOURCES:.cpp=.o)

MEDIA_LIBDIR= 
MEDIA_INCDIR= 

TARGET=libencoder.so

all: $(TARGET)

clean: 
	rm -f $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
