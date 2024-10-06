OBJS = source/mine.cpp

CC = g++

OBJ_NAME = mine

all :
	$(CC) $(OBJS) -std=c++11 -static-libgcc -static-libstdc++ -o $(OBJ_NAME)
