CC = gcc
FLAGS = -g -Wall -Wextra
OBJETS = horse.o
all:horse

horse:$(OBJETS)
	$(CC) $(FLAGS) -o $@ $(OBJETS)

horse.o:horse.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJETS)
