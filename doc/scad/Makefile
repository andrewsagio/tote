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
	bom-arduino.png \

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

assembly04.png: assembly04.scad
	$(SCAD) -o $@ $< --camera=23.98,19.00,-18.99,210.40,0.00,219.10,263.43

gait01.png: gait01.scad
	$(SCAD) -o $@ $< --camera=0,0,0,38.20,0,341.60,446.13

gait02.png: gait02.scad
	$(SCAD) -o $@ $< --camera=0,0,0,38.20,0,341.60,446.13

gait03.png: gait03.scad
	$(SCAD) -o $@ $< --camera=0,0,0,38.20,0,341.60,446.13

gait04.png: gait04.scad
	$(SCAD) -o $@ $< --camera=-3.53,14.94,16.47,48.00,0.00,358.40,495.70

gait05.png: gait05.scad
	$(SCAD) -o $@ $< --camera=-3.53,14.94,16.47,48.00,0.00,358.40,495.70

gait06.png: gait06.scad
	$(SCAD) -o $@ $< --camera=-3.53,14.94,16.47,48.00,0.00,358.40,495.70

gait07.png: gait07.scad
	$(SCAD) -o $@ $< --camera=-3.53,14.94,16.47,48.00,0.00,358.40,495.70

bom-arduino.png: bom-arduino.scad
	$(SCAD) -o $@ $< --camera=9.88,18.49,-10.33,30.50,0.00,235.70,140.00

