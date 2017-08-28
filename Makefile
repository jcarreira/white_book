all: nth_permutation

CPPFLAGS=-Wall -Werror -ansi -ggdb -std=c++11 

nth_permutation: nth_permutation.cpp
	g++ $(CPPFLAGS) nth_permutation.cpp -o nth_permutation
