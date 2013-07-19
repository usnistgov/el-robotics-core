# type "make" command in Unix to create pdf file 

FILE = USARSimRos

all:
	rm -f ${FILE}.pdf
	pdflatex ${FILE}
	bibtex ${FILE}
	pdflatex ${FILE}
	pdflatex ${FILE}
	
draft:
	rm -f ${FILE}.pdf
	pdflatex ${FILE}
#	dvipdf ${FILE}

tar:
	tar cvf ${FILE}.tar ${FILE}.tex *.tex *.bib Figures/*/*.png Figures/*/*.jpg *.cls *.sty *.bst Makefile
	gzip ${FILE}.tar

zip:
	zip ${FILE}.zip ${FILE}.tex *.bib images/*.png images/*.jpg *.cls *.bst Makefile

abstract:
	latex abstract
	dvips -o abstract.ps abstract
	ps2pdf abstract.ps abstract.pdf

clean:
	(rm -rf *.ps *.log *.dvi *.aux *.*% *.lof *.lop *.lot *.toc *.idx *.ilg *.ind *.bbl *blg)
