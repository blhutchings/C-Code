A simple keylogger using the input-device (/dev/input/event#) and save contents into a file
Needs root privileges to read the event file

First change the settings then compile.

Compile:
	cc keylogger.c

Run with:
	sudo ./COMPILED_FILE.out 
