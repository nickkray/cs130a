CXX = g++ 

CXXFLAGS = -g -std=c++11 -Wall

all: gauchobook

gauchobook: main.o helpers.o UserNetwork.o User.o Wall.o WallPost.o
	${CXX} $^ -o $@
clean:
	/bin/rm -f gauchobook *.o
