CC=g++ -w
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp board/board_util.h board/board_util.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) ; $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: ; $(CC) $(CFLAGS) $< -o $@

clean: ; rm -rf *o main
