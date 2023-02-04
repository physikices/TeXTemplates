ls main.tex | entr /bin/sh -c "pdflatex main.tex && bibtex main.aux && pdflatex main.tex && pdflatex main.tex && pkill -HUP mupdf"
