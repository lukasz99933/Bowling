CXX=g++
CFLAGS=--std=c++11  -Wall -Wextra -Wpedantic -Iincludes

bowling: *.cpp *.hpp
	$(CXX) main.cpp bowling.hpp bowling.cpp -o $@ $(CFLAGS)

clean:
	rm bowling
