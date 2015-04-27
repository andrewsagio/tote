IMAGES=\
	tote.png pkubik.png \
	assembly01.png \
	assembly01b.png \
	assembly02.png \
	assembly03.png \
	assembly04.png \
	gait01.png \
	gait02.png \
	gait03.png \
	gait04.png \
	gait05.png \
	gait06.png \
	gait07.png \

SIZE=1280,960
SCAD=openscad --imgsize=$(SIZE) --projection=p -m make

all: images

clean:
	rm -f -- $(IMAGES)

images: $(IMAGES)

%.png: %.scad
	$(SCAD) -o $@ $<

tote.png: tote.scad
	$(SCAD) -o $@ $< --camera=12.40,-17.13,-29.65,45.90,0,30.60,401.52
