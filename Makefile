sources = face.c 
ccflags = -Wall -g -fsanitize=address
CC = gcc
target = b
link = ncursesw
all:
	$(CC) $(sources) $(ccflags) -o $(target) -l$(link)