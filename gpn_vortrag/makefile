
all: folien.pdf api_demo.pdf folien_uebersicht.pdf

folien.pdf: folien.md makefile
	pandoc folien.md -fmarkdown -t beamer -o folien.pdf \
		--slide-level=2\
		--normalize \
		-M lang:german\
		-M subtitle:'Ein Debug-Framework für OpenCV'\
		-V theme:Singapore\
		-V colortheme:beaver

folien_uebersicht.pdf: folien.md makefile
	pandoc folien.md -fmarkdown -o folien_uebersicht.pdf \
		-M lang:german \
		--toc \
		--number-sections \
		-V documentclass:scrartcl\
		-V papersize:"a4paper" \

api_demo.pdf: api_demo.md makefile
	pandoc api_demo.md -fmarkdown -o api_demo.pdf \
		-M lang:german \
		--toc \
		--number-sections \
		-V documentclass:scrartcl\
		-V papersize:"a4paper" \

delete:
	rm folien.pdf api_demo.pdf folien_übersicht.pdf
