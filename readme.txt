Compilation for this program is standard: gcc -o [name]

You are trapped in an underground research facility, and your only hope of escape
is activating the last escape vault via the terminal. This game simulates that terminal.
Once you are in, navigate through the terminal to find clues on how to access the escape
vault controls. 

I did not get a chance to complete the game, but this demo version contains all of the
concepts I was required to use.

>>No measures have been taken to prevent incorrect user input from breaking the game!

GUIDE/FUTURE PLANS:

The first puzzle requires you to enter a password to enter the terminal. If you guess
random entries, after 4 incorrect guesses, text is printed that hints to look up. 
if you scroll up far enough, a grid of X's is shown where some X's are replaced with 
numbers. The password consists of  the coordinates of each number in sequence. The 
password is H5A6E9B7. 

The second puzzle is not functioning yet, but it requires the user to input a PIN
number to access the admin menu. The PIN is randomly generated and the user will guess
it digit-by-digit. after entering each digit the terminal will tell the user how many
digits he/she guessed correctly. The correct guesses include placement, so the user has
a clue as to how close he/she is. There is also a limited number of times the user can 
before he/she is kicked out of the terminal.


The main menu is fully implemented in this version but if you try to advance into the 
administrative menu there is still no method to return to the main menu. The 
administrative menu is coded into the game, but since the PIN guessing puzzle isn't 
functioning, there is no way to access the admin menu currently.

The game's admin menu will be a replica of the main menu plus extra administrative
options. one of these options will be exit vault control, which will be 'corrupted',
leading the player to find another way through. There will be hints hidden throughout 
the admin menu that will guide the player to the file system, where they have to do some
file manipulation to be able to access vault door controls and exit.