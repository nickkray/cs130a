CXX = clang++ -g

CXXFLAGS = -Wall

all: gauchobook

gauchobook: main.o helpers.o UserNetwork.o User.o Wall.o WallPost.o
  ${CXX} $^ -o $@

clean:
  /bin/rm -f gauchobook *.o
