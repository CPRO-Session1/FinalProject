#Camera Syntax
##Events
###Watching Events
To write a normal event, the syntax is "d<n>] <s>"
Where <s> is the string to print and <n> is the delay between that event and the next one
###Switching Events
Switching events are only sent if the player switches to the camera that calls them between the time it is called and the time it is called + the duration it specifies
The syntax is: "s<n>] <s>"
Where <s> is the string to print and <n> is the duration
##Exiting
To automatically exit the game, write "_exit" or "_end" at the end of the files
