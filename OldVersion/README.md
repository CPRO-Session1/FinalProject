#How to play the game
The game consists of a series of messages that print out at specific times. The player interacts with the game using commands. Although not required, before writing a command, press enter to pause the messages, then write the command, then press enter again to unpause them. The commands are as follows.
### Pausing the game
To pause the game, press enter
### Changing the camera
To change the camera, type "camera <name>"
To get a list of available cameras, type "camera"
### Listing the commands
To get a list of commands, type "help"
### Quitting
To quit, type "quit"
#How to make a game
The game runs using .txt files (which I call cameras, in this context) in the Cameras directory. When it launches, its camera will be start.txt, so that should be written first. There are 3 possible commands for a camera, which are the following.
### Witnessed Events
Witnessed events are events that only print if the player is watching the camera that the event is on when it occurs. The syntax for a witnessed event is `"d<n>] <s>"` where `<n>` is the delay, in seconds, between the event in question and the event following it, and `<s>` is the message to be sent.
### Ongoing Events
Ongoing events are events that only print if the player switches to the camera that the event is on after the event starts and before it stops. The syntax for an ongoing event is `"s<n>] <s>"` where `<n>` is the time, in seconds, between the event starting and the event ending, and `<s>` is the message to be sent
### Automatic exit
To automatically quit the program, put "_end" or "_exit" at the end of the file.
# How to compile it
to compile it, use `gcc textAdventure.c -o textAdventure -lpthread`
