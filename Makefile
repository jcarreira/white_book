PDF = note
CPPFLAGS=-Wall -Werror -ansi -ggdb -std=c++11 

all: $(PDF) nth_permutation kmp


nth_permutation: nth_permutation.cpp
	g++ $(CPPFLAGS) nth_permutation.cpp -o nth_permutation

kmp: kmp.cpp
	g++ $(CPPFLAGS) kmp.cpp -o kmp


note: note.tex
	pdflatex $^

clean:
	rm nth_permutation *.log *.aux *.pdf *.toc -rf
