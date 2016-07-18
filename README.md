Hello! This is my final project.  
If you plan on writing a game in this, you should definitely read the "issues" section on the bottom of this readme
#Playing a game
The game consists of a series of messages that print out at specific times. The messages change depending on which "camera" the user is looking through. To start the game with the default camera, launch the game normally. To start the game with a different camera, launch the game with the camera's name as an argument.
##Commands
The player interacts with the game using commands. Although not required, before writing a command, press enter to pause the messages, then write the command, then press enter again to unpause them. The commands are as follows.
### Pausing the game
To pause the game, press enter
### Changing the camera
To change the camera, type `"camera <camera name>"`  
To get a list of available cameras, type "cameras"  
### Listing the commands
To get a list of commands, type "help"
### Quitting
To quit, type "quit"
# Writing a game!
## Events!
### Instant Events
  To print a line of text to the screen, use an instant event. It will only print if the player is using the camera that the event is declared on when it is scheduled to print  
  to write an instant event, use `i <text>`
### Ongoing Events
  Ongoing events are events that are carried out over time. They will only print if the player switches to the camera that they are declared on after they are scheduled to start and before they are scheduled to end.
  
  There are two different ways to specify the duration of the event. The first is telling it the time that it will end.  
  To do so, use `oa <time that it will end> <text>`
  
  The other way is to tell it how long the event takes.  
  To do so, use `or <duration> <text>`
## Delays
### Pausing
  The game can pause itself, in case that functionality is ever required.  
  To pause the game, use `pause`  
  This will print out a message informing the player that the game has been paused. If this is not desired, the game can be paused without telling the player.
  To do so, use `pause_silent`
### Waiting
  To advance the in-game time, the game can wait a certain amount of seconds.  
  To make the game wait until a specific time, use `wa <time to wait until>`  
  To make the game wait a specific amount of time, use `wr <amount of time to wait>`
## Cameras!
The game runs using .txt files (which I call cameras, in this context) in the Cameras directory. By default, when the game launches, the camera will be start.txt. If you want to start the game with a different camera, you can launch it with the camera's name as an argument or have the first line of start.txt redirect the camera to a different file.
To change the camera automatically, use `camera <new camera name>`
## Exiting!
To exit the game, use `quit`

#Issues! (These will all be fixed in a future update)
* The list of cameras doesn't automatically update. If a new camera is added, the CAMERA_LIST string in textadventure.c should be modified to reflect that.
* There's nothing marking the end of an instruction type and the beginning of the instruction's arguments, which makes the camera files a bit annoying to read
