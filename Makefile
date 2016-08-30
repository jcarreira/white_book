MAIN = note.tex

all:
	pdflatex $(MAIN)

clean:
	rm *.log *.aux *.pdf *.toc -rf
