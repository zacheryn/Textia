#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <Windows.h>
#include <iostream>

#ifndef ANSI_SEQUENCES
#define ANSI_SEQUENCES
const char normal[] = { 0x1b,'[','0',';','3','9','m',0 };
const char Bnormal[] = { 0x1b,'[','1',';','3','9','m',0 };
const char black[] = { 0x1b,'[','0',';','3','0','m',0 };
const char red[] = { 0x1b,'[','0',';','3','1','m',0 };
const char green[] = { 0x1b,'[','0',';','3','2','m',0 };
const char Bgreen[] = { 0x1b,'[','1',';','3','2','m',0 };
const char Dgreen[] = { 0x1b,'[','2',';','3','2','m',0 };
const char yellow[] = { 0x1b,'[','0',';','3','3','m',0 };
const char blue[] = { 0x1b,'[','0',';','3','4','m',0 };
const char Upurple[] = { 0x1b,'[','4',';','3','5','m',0 };
const char cyan[] = { 0x1b,'[','0',';','3','6','m',0 };
const char lgray[] = { 0x1b,'[','0',';','3','7','m',0 };
const char dgray[] = { 0x1b,'[','0',';','3','8','m',0 };
const char Bred[] = { 0x1b,'[','1',';','3','1','m',0 };
//for bold colors, just change the 0 after the [ to a 1
//for underlined colors, just change the 0 after the [ to a 4
#endif

//Contains several convenient functions
class Utility {
private:

	//OPTIONS (Initialized to defaults)
	int textSpeed;
	bool profanity;;

public:

	//Constructor to initialize default settings
	Utility() :
	textSpeed{ 50 }, profanity{ true } {}

	//Outputs the string character by character with a very small delaay
	void slowRead(const std::string&);

	//SlowRead overload to specify delay between characters
	void slowRead(const std::string&, const int);

	//Begins options selection
	void options();

	//Delays the program for a given number of milliseconds
	void delay(const int timer);
};

#endif
