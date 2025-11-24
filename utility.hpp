#pragma once

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <chrono>
#include <thread>
#include <string_view>

#ifndef ANSI_SEQUENCES
#define ANSI_SEQUENCES
constexpr char normal[] = { 0x1b,'[','0',';','3','9','m',0 };
constexpr char Bnormal[] = { 0x1b,'[','1',';','3','9','m',0 };
constexpr char black[] = { 0x1b,'[','0',';','3','0','m',0 };
constexpr char red[] = { 0x1b,'[','0',';','3','1','m',0 };
constexpr char green[] = { 0x1b,'[','0',';','3','2','m',0 };
constexpr char Bgreen[] = { 0x1b,'[','1',';','3','2','m',0 };
constexpr char Dgreen[] = { 0x1b,'[','2',';','3','2','m',0 };
constexpr char yellow[] = { 0x1b,'[','0',';','3','3','m',0 };
constexpr char blue[] = { 0x1b,'[','0',';','3','4','m',0 };
constexpr char Upurple[] = { 0x1b,'[','4',';','3','5','m',0 };
constexpr char cyan[] = { 0x1b,'[','0',';','3','6','m',0 };
constexpr char lgray[] = { 0x1b,'[','0',';','3','7','m',0 };
constexpr char dgray[] = { 0x1b,'[','0',';','3','8','m',0 };
constexpr char Bred[] = { 0x1b,'[','1',';','3','1','m',0 };
//for bold colors, just change the 0 after the [ to a 1
//for underlined colors, just change the 0 after the [ to a 4
#endif


template<class T>
concept durationType = std::is_convertible_v<T, std::chrono::nanoseconds>;

template<class T> requires durationType<T>
void delay(T d) noexcept {
	std::this_thread::sleep_for(d);
}

// Contains some useful functions and tracks certain settings
class Utility {
private:

	// The delay between each character being printed when calling slowRead
	std::chrono::milliseconds characterDelay;

	// The volume multiplier for all of the music (Range is [0.0 - 1.0])
	float musicVol;

	// The volume multiplier for all of the sound effects (Range is [0.0 - 1.0])
	float sfxVol;

public:

	Utility() noexcept;

	void setSettings() noexcept;

	// Takes a std::string_view, and prints out one character at a time to stdout.
	// Output will always be to stdout, so no reason to take an istream as input.
	void slowRead(std::string_view) const noexcept;
};

#endif