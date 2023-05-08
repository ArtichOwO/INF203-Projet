.PHONY: clean

compte_rendu.pdf: compte_rendu.tex
	@echo TEX $@
	@pdflatex $^ -o $@

clean:
	@rm -f *.aux *.log *.out *.toc *.pdf
	@echo CLEAN
