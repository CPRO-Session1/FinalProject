# Astroshark
## Sean Kee

### Instructions
Must have installed:
 -  In SDL Folder
less INSTALL.txt and follow instructions on how to install SDL2

sudo apt-get install these:
 - libsdl2-2.0-0
 - libsdl2-dbg
 - libsdl2-dev
 - libsdl2-image-2.0.0
 - libsdl2-image-dbg
 - libsdl2-image-dev

If opening code, use sublime or a text editor that's NOT vim.

Compile command:
gcc astroshark.c -o astroshark -lm -l SDL2 -l SDL2_image

### Main Goals
 ~~- Create operational window~~
 	~~ * Operating close window button~~
 	~~ *Create boundaries~~
 ~~ - Create functional space ship~~
 	~~ * Movement with WASD and rotation with arrow keys~~
~~ - Create asteroids to shoot at, using random generation~~
 ~~	* Random asteroid spawn location, with random velocity~~
 	* Gets destroyed when hit by laser
 ~~ - Create bullets/lasers ~~

### Secondary Goals
 - Create separate sprites for different things
 - Enemy AI
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
 - Create Scoring System

### Additional Comments

Even though we did not go over any GUI, I chose this project mainly to see if I could actually do it. With really no "real" prior programming, I completely underestimated the amount of time and work it would take to accomplish such a project. That being said, all the goals I did not reach were essentially due to the lack of time. The only real resource I was able to find to help me was the wiki on SDL. Other than that, everyone else on the internet seemed to think it was a good idea to completely drop C and use C++, so essentially there were few possible sources. All the algorithms used in my program to calculate different things were not taken from any source, and were created by me. Anything related to SDL in terms of general usage, I referred to the wiki.


Note: Any large chunks of code that are commented out are additional features that are either not complete or do not yet fully work. The core mechanics of the game work just fine.


### References
https://wiki.libsdl.org/
http://www.cplusplus.com/reference/cmath/sin/
