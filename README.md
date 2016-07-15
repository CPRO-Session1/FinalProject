# Astroshark
## Sean Kee

### Instructions
Must have installed:
 - SDL2
 - libsdl2-2.0-0
 - libsdl2-dbg
 - libsdl2-dev
 - libsdl2-image-2.0.0
 - libsdl2-image-dbg
 - libsdl2-image-dev

 In SDL Folder
less INSTALL.txt

Command:
gcc astroshark.c -o astroshark -lm -l SDL2 -l SDL2_image
### Main Goals
 ~~- Create operational window~~
 	~~ * Operating close window button~~
 	~~ *Create boundaries~~
 ~~ - Create functional space ship~~
 	~~ * Movement with WASD and rotation with arrow keys~~
 - Create asteroids to shoot at, using random generation
 	* Random asteroid spawn location, with random velocity
 	* Gets destroyed when hit by laser
 ~~ - Create bullets/lasers ~~

### Secondary Goals
 - Create separate sprites for different things
 - Create menu system
 	* Main menu
 	* Pause menu
 	* Options
 - Realistic control system simulating actual space flight (acceleration etc.)
 	* Fix rotation center
 	* Add acceleration and "realistic" motion
 	* Mouse functionality
 - Powerups
 	* Ultimate Shark mode(god)
 	* Double shoot
 - Clean Up
 	* Audio (SFX)
 	* Better sprites

### Additional Comments


### References
https://wiki.libsdl.org/
http://www.cplusplus.com/reference/cmath/sin/
