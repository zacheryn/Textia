#include "utility.hpp"

#include <iostream>

Utility::Utility() noexcept
: characterDelay{ 50 }
, musicVol{ 1.0 }
, sfxVol{ 1.0 } {

}

void Utility::setSettings() noexcept {
	// Stuff will happen here later
}

void Utility::slowRead(std::string_view s) const noexcept {
	for (const char c : s) {
		std::this_thread::sleep_for(characterDelay);
		std::cout << c << std::flush;
	}
}