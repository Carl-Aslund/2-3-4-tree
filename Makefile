CXX = clang++
CXX_FLAGS = -c -g -std=c++11 -Wall -Wextra -pedantic

all: tree-test

tree-234.o: tree-234.cpp tree-234.hpp testing-logger.hpp
	$(CXX) $(CXX_FLAGS) tree-234.cpp

testing-logger.o: testing-logger.cpp testing-logger.hpp
	$(CXX) $(CXX_FLAGS) testing-logger.cpp

tree-test.o: tree-test.cpp tree-234.hpp testing-logger.hpp
	$(CXX) $(CXX_FLAGS) tree-test.cpp

tree-test: tree-234.o tree-test.o testing-logger.o
	$(CXX) -o tree-test tree-234.o tree-test.o testing-logger.o

clean:
	rm -rf tree-test *.o
