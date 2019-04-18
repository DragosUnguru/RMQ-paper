.phony: build run test clean

CC = g++
CFLAGS= -Wall
DEPS = $(wildcard *.h)
OBJ = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
EXEC = tema

build: $(EXEC)
		
$(EXEC):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c  $< -o $@ 

check:
	sh checker.sh

clean:
	rm -f $(EXEC) $(OBJ)

