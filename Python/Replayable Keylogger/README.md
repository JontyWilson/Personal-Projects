# Overview
Created a multi-threaded keylogger that allows me to track which key was pressed and for how long, outputting the results to a txt file that allows me to replay the exact sequence of key presses according to their timing and duration. 

I implemented this to automate a path traveled in a video game purely using user inputs. 

A notable challenge was offseting the length of time a key was pressed by the latency of the game server. If a key was pressed by the user, but there was 500ms of latency, this means the key press was only registered after 0.5s. This messed with the timing of the program a lot. The solution was to ping the server and offset the timing by the latency. 