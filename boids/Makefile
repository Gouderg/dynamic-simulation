CC = g++
CFLAGS = #-W -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard src/*.cpp)
OBJS = $(SRC:.cpp=.o)
 
all : boids clean

boids : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm src/*.o

git:
	rm boids