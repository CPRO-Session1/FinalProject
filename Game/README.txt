# Final Project

It’s a text adventure game.
I picked a text adventure game to do because it seemed accomplishable and I like playing games.

## Compliation
gcc game.c

## How to play
Type in commands at the >> prompt. Available commands are:
 - goto [location] will print out a statement when you move to the room then print out the new room summary
 - take [item] will move the item into your inventory
 - look - print a look summary
 - read note - will display collected notes
 - yell - will make you yell. (doesn't do anything unless you're in the yard)
 - cook (only in kitchen)
 - QUIT - Quits game
 - help - prints this

## Differences from proposal
 - Player has more variables, like inventory size, has_poo, has_backpack, notes_read.
 - never implemented enumerator, just used strings instead
 - Room summaries can change, though none of them really do as I put in a separate "room" with a different functionality. Room pointers can point to different rooms too, so you can create multiple rooms with the same room name.
 - Commands are each their own individual functions and could be called from the get_args function but I didn't have time to really change this so they're all in main. 
 - Look in bag not implemented, it just prints inventory all the time as it got cumbersome to try to just look in bag
 - there is no Open command as it would have made it unnecessarily complicated
 - Go is goto 
 - Help would be easy to put in, though I feel it was redundant as the game is pretty easy.
 - put would have also made the game too complicated.
 - there are new room-specific commands like cook and rap that help you to win the game.

## How to win
Use these commands in this order:
 - goto bedroom
 - take backpack
 - take note
 - goto yard
 - take note
 - yell
 - goto park
 - take note
 - take dog poo
 - goto yard
 - goto kitchen
 - cook dog poo
 - take note
 - take rusty key
 - goto yard
 - goto shack
 - take note
 - read note
 - rap

Use these commands to lose the game:
 - goto bedroom
 - take backpack
 - goto yard
 - goto park
 - goto anywhere
alternatively: QUIT or goto QUIT works well.