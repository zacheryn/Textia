#include "locations.hpp"
#include <iostream>
#include <conio.h>

using Locations::location;
using Locations::intro;
using Locations::startingForest;

void location::waitKey() const noexcept {
    util->slowRead(std::string_view("Press Any key to continue..."));
    //std::cout << "Press Any key to continue..." << std::flush;

    // Clear any inputs prior to reaching the continue point
    while (_kbhit()) (void)_getch();
    //std::cout << '\n' << _kbhit() << std::endl;
    // Take the input to the move forward
    (void)_getch();

    // Clear any inputs to clean out buffer in case of wide characters
    while (_kbhit()) (void)_getch();

    std::cout << '\n' << std::endl;
}

void intro::printTitle() const noexcept {
    using namespace std::chrono_literals;
    // These are ASCII art of the title, they look much better when printed.
    // I need to escape all of the '\' characters, so it makes it look jumbled here.
    std::cout << "         ,-.-.      ,----.              _,.----.      _,.---._            ___       ,----.  \n"
              << ",-..-.-./  \\==\\  ,-.--` , \\   _.-.    .' .' -   \\   ,-.' , -  `.   .-._ .'=.'\\   ,-.--` , \\ \n"
              << "|, \\=/\\=|- |==| |==|-  _.-` .-,.'|   /==/  ,  ,-'  /==/_,  ,  - \\ /==/ \\|==|  | |==|-  _.-` \n"
              << "|- |/ |/ , /==/ |==|   `.-.|==|, |   |==|-   |  . |==|   .=.     ||==|,|  / - | |==|   `.-. \n"
              << " \\, ,     _|==|/==/_ ,    /|==|- |   |==|_   `-' \\|==|_ : ;=:  - ||==|  \\/  , |/==/_ ,    / \n"
              << " | -  -  , |==||==|    .-' |==|, |   |==|   _  , ||==| , '='     ||==|- ,   _ ||==|    .-'  \n"
              << "  \\  ,  - /==/ |==|_  ,`-._|==|- `-._\\==\\.       / \\==\\ -    ,_ / |==| _ /\\   ||==|_  ,`-._ \n"
              << "  |-  /\\ /==/  /==/ ,     //==/ - , ,/`-.`.___.-'   '.='. -   .'  /==/  / / , //==/ ,     / \n"
              << "  `--`  `--`   `--`-----`` `--`-----'                 `--`--''    `--`./  `--` `--`-----``  \n"
              << std::endl;

    delay(2s);

    std::cout << "                               ,--.--------.    _,.---._     \n"
              << "                              /==/,  -   , -\\ ,-.' , -  `.   \n"
              << "                              \\==\\.-.  - ,-.//==/_,  ,  - \\  \n"
              << "                               `--`\\==\\- \\  |==|   .=.     | \n"
              << "                                    \\==\\_ \\ |==|_ : ;=:  - | \n"
              << "                                    |==|- | |==| , '='     | \n"
              << "                                    |==|, |  \\==\\ -    ,_ /  \n"
              << "                                    /==/ -/   '.='. -   .'   \n"
              << "                                    `--`--`     `--`--''     \n"
              << std::endl;

    delay(2s);

    std::cout << Bred
              << "       ,--.--------.     ,----.          ,-.--, ,--.--------.   .=-.-.  ,---.      \n"
              << "      /==/,  -   , -\\ ,-.--` , \\.--.-.  /=/, .'/==/,  -   , -\\ /==/_ /.--.'  \\     \n"
              << "      \\==\\.-.  - ,-./|==|-  _.-`\\==\\ -\\/=/- /  \\==\\.-.  - ,-./|==|, | \\==\\-/\\ \\    \n"
              << "       `--`\\==\\- \\   |==|   `.-. \\==\\ `-' ,/    `--`\\==\\- \\   |==|  | /==/-|_\\ |   \n"
              << "            \\==\\_ \\ /==/_ ,    /  |==|,  - |         \\==\\_ \\  |==|- | \\==\\,   - \\  \n"
              << "            |==|- | |==|    .-'  /==/   ,   \\        |==|- |  |==| ,| /==/ -   ,|  \n"
              << "            |==|, | |==|_  ,`-._/==/, .--, - \\       |==|, |  |==|- |/==/-  /\\ - \\ \n"
              << "            /==/ -/ /==/ ,     /\\==\\- \\/=/ , /       /==/ -/  /==/. /\\==\\ _.\\=\\.-' \n"
              << "            `--`--` `--`-----``  `--`-'  `--`        `--`--`  `--`-`  `--`         \n"
              << "\n\n\n\n"
              << std::endl
              << normal;

    delay(3s);
    waitKey();
}

void intro::visit() noexcept {
    // Just a check to make sure the intro isn't replayed
    if (isVisited()) return;
    ++numVisits;

    printTitle();
    util->slowRead("Welcome to my poorly made text-based adventure game! It will most likely be horribly written\n");
    util->slowRead("and hard to follow or control, but I mean, that's definitely part of the intended experience.\n\n");
    std::cout << Bnormal; util->slowRead("TUTORIAL\n"); std::cout << normal;
    util->slowRead("I know text based adventures are pretty self-explanatory, but I'm saying this all anyway.\n");
    util->slowRead("For each event you encounter, you will be given a list of numbered choices. Simply respond\n");
    util->slowRead("with the number of whichever one of the listed choices you wish to make.\n\n");
    util->slowRead("P.S. If at any point (after you choose a name) you want to view your inventory,\n");
    util->slowRead("just type \'Inventory\' (not case sensitive).\n\n");
    waitKey();
}

void startingForest::visit() noexcept {
	++numVisits;
	util->slowRead(description);
}