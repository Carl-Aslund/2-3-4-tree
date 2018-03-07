CXX = clang++
CXX_FLAGS = -c -g -std=c++11 -Wall -Wextra -pedantic

all: tree-test

234-tree.o: 234-tree.cpp 234-tree.hpp testing-logger.hpp
	$(CXX) $(CXX_FLAGS) 234-tree.cpp

testing-logger.o: testing-logger.cpp testing-logger.hpp
	$(CXX) $(CXX_FLAGS) testing-logger.cpp

tree-test.o: tree-test.cpp treeset.hpp testing-logger.hpp
	$(CXX) $(CXX_FLAGS) tree-test.cpp

tree-test: 234-tree.o tree-test.o testing-logger.o
	$(CXX) -o tree-test 234-tree.o tree-test.o testing-logger.o

clean:
	rm -rf tree-test *.o
