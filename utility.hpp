#pragma once

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <chrono>
#include <string_view>

// Contains some useful functions and tracks certain settings
class Utility {
private:

	// The delay between each character being printed when calling slowRead
	std::chrono::milliseconds delay;

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