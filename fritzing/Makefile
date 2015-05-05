FRITZING=fritzing
PCBS=pcb2.zip

all: $(PCBS)

%.zip: %.fzz
	mkdir -p gerber
	$(FRITZING) $< -gerber gerber
	mv gerber/$*_contour.gm1 gerber/$*_outline.gbr
	zip -0 -m -j $@ gerber/*
	rmdir --ignore-fail-on-non-empty gerber
