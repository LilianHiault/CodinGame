CC = gcc
FLAGS = -g -Wall -Wextra
OBJETS = thor.o

all:thor

thor:$(OBJETS)
	$(CC) $(FLAGS) -o $@ $(OBJETS)

thor.o:thor.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJETS)
