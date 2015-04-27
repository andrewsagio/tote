IMAGES=tote.png pkubik.png assembly/step01.png
CAMERA=12.40,-17.13,-29.65,45.90,0,30.60,401.52
SIZE=1280,960

all: images

clean:
	rm -f -- $(IMAGES)

images: $(IMAGES)

%.png: %.scad
	openscad --camera=$(CAMERA) --imgsize=$(SIZE) --projection=p -m make -o $@ $<

