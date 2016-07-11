##Overview
This will be a text adventure where the player "watches" an event unfold from a security camera. They will not have any control over the events, but they might have a say in the futures of those involved. It will be more of an interactive story than an actual game.
##How I'll do it
The story will be input via several text files, one for each camera. Each message will be read to a "message" data type, which will store the string in question, in addition to the delay between the message and the one before it. The messages will be stored in an array which will be slowly iterated through (the iteration will have to wait for the delays) and printed.
##Reasons
I picked this project because I initially became interested in programming because I wanted to make a text adventure, and nothing seems like a better challenge than making a string-based game in c. The idea of several stories occurring at once and affecting each other also interests me, and I want to explore that in the game. I also like games that have to be played through several times to get the full story, so that's why I decided on making this.
