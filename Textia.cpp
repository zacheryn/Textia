#include "Player.h"
#include "ansi_escapes.h"
#include "Audio.h"
#include "Locations.h"
#include "Utility.h"
#include <algorithm>
#include <limits>
#include <conio.h>

using namespace std;

//Takes in the path to EXE and returns the path to the 'Sounds' folder.
//The 'Sounds' folder MUST be in the same directory as the executable
//Example path: "C:\Users\Name\Textia\Textia-Windows.exe"
string getPathToSounds(string s) {
    return s.substr(0, s.find_last_of("\\/")) + "\\Sounds\\";
}

//Prints the intro message
void intro(Utility&);

//This is the main function,
//That's all to say about it.
//Seriously, that's it. There's nothing
//else to say about it. Move on.
int main(int argc, char* argv[]) {
    //Don't worry about this
    //It just speeds up I/O
    ios_base::sync_with_stdio(false);

    //Used to make windows console use ansi escape sequences
    //(Let's me do fancy colors)
    setupConsole();

    //Music:
    // 
    //New Dawn by Benjamin Tissot
    //  Attribution text:
    //  Music I use: Bensound
    //  License code: MUAU4FA9QYNBCAG7
    Audio soundtrack(getPathToSounds(string(argv[0])));
    soundtrack.Play("newdawn.wav", 0.1f, true);

    Utility util;

    //Effectively a title screen
    intro(util);

    //Give the playes a chance to adjust a few options (only chance)
    util.options();

    string input;
    //Make sure the player actually enters a name;
    while (input.empty()) {
        util.slowRead("Now please enter your name: ");
        getline(cin, input);
        if (!input.empty()) {
            util.slowRead("Is "); cout << Bnormal; util.slowRead(input);
            cout << normal; util.slowRead(" your name?\n\t1. Yes\n\t2. No\n");
            char c;
            cin >> c;
            while (c != '1' && c != '2') {
                util.slowRead("Is "); cout << Bnormal; util.slowRead(input);
                cout << normal; util.slowRead(" your name?\n\t1. Yes\n\t2. No\n");
                cin.ignore((numeric_limits<streamsize>::max)());
                cin >> c;
            }
            if (c == '1') {
                break;
            }
            else {
                getline(cin, input);
                input.clear();
            }
        }
    }

    Locations loc(util);

    //Greet player
    Player player(input, util);
    util.slowRead("Nice to properly meet you then, "); cout << Bnormal;
    util.slowRead(player.getName()); cout << normal; util.slowRead(".\n\n\n\n\n");

    util.delay(3000);

    //Now it actually begins...
    util.slowRead("You awaken to find yourself face down on a mound of dirt surrounded by trees. The smell\n");
    util.slowRead("pine trees fills your lungs as you take in a long breathe of the fresh forest air.\n");

    //Waking up
    input.clear();
    while (true) {
        util.slowRead("\t1. It smells nice. I'm just gonna stay here.\n\t2. I'll get up and look around.\n");
        cin >> input;
        if (input != "1" && input != "2") {
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            if (input == "INVENTORY") {
                player.showInventory();
            }
        }
        else {
            break;
        }
    }
    //Taking a nap
    if (input == "1") {
        size_t sits = 1;
        while (sits < 5) {
            util.slowRead("You close your eyes and just breathe. The forest air is so extremely relaxing that you\n");
            util.slowRead("begin to doze off. You're not sure exactly how long you were asleep, but you have no regrets.\n");

            input.clear();
            while (input != "1" && input != "2") {
                transform(input.begin(), input.end(), input.begin(), ::toupper);
                if (input == "INVENTORY") {
                    player.showInventory();
                    --sits;
                    break;
                }
                cout << green; util.slowRead("\t1. I'm extremely confortable.\n"); cout << normal;
                util.slowRead("\t2. As nice as this is, I should probably get moving.\n");

                cin >> input;
            }

            if (input == "2") break;
            ++sits;
        }

        //Long nap
        if (sits >= 5) {
            cout << green;
            util.slowRead("You've been lying on the ground breathing in this forest air for so long that you have become one\n");
            util.slowRead("with the forest. Vines, fungus, and moss have grown all over you're body, pinning you to the ground.\n");
            util.slowRead("Of course, you are completely content with this. Maybe even happy. A slight smile forms on your face\n");
            util.slowRead("as you slowly waste away, returning to the forest. Returning to the earth.\n\n");
            cout << Dgreen;
            util.delay(150);
            util.slowRead("You are at peace.\n", 150);
            cout << normal;
            util.delay(2000);
            util.slowRead("Press any key to close...");
            _getch();

            restoreConsole();
            return 0;
        }
    }//Waking up

    //(Travel) to the spawn forest
    loc.spawnForest();

    //The End
    util.delay(2000);
    util.slowRead("Press any key to close...");
    _getch();
    //Brings the console back to normal.
    restoreConsole();
    return 0;
}//main

void intro(Utility &util) {
    cout << "         ,-.-.      ,----.              _,.----.      _,.---._            ___       ,----.  \n"
        << ",-..-.-./  \\==\\  ,-.--` , \\   _.-.    .' .' -   \\   ,-.' , -  `.   .-._ .'=.'\\   ,-.--` , \\ \n"
        << "|, \\=/\\=|- |==| |==|-  _.-` .-,.'|   /==/  ,  ,-'  /==/_,  ,  - \\ /==/ \\|==|  | |==|-  _.-` \n"
        << "|- |/ |/ , /==/ |==|   `.-.|==|, |   |==|-   |  . |==|   .=.     ||==|,|  / - | |==|   `.-. \n"
        << " \\, ,     _|==|/==/_ ,    /|==|- |   |==|_   `-' \\|==|_ : ;=:  - ||==|  \\/  , |/==/_ ,    / \n"
        << " | -  -  , |==||==|    .-' |==|, |   |==|   _  , ||==| , '='     ||==|- ,   _ ||==|    .-'  \n"
        << "  \\  ,  - /==/ |==|_  ,`-._|==|- `-._\\==\\.       / \\==\\ -    ,_ / |==| _ /\\   ||==|_  ,`-._ \n"
        << "  |-  /\\ /==/  /==/ ,     //==/ - , ,/`-.`.___.-'   '.='. -   .'  /==/  / / , //==/ ,     / \n"
        << "  `--`  `--`   `--`-----`` `--`-----'                 `--`--''    `--`./  `--` `--`-----``  \n"
        << endl;

    util.delay(2000);

    cout << "                               ,--.--------.    _,.---._     \n"
        << "                              /==/,  -   , -\\ ,-.' , -  `.   \n"
        << "                              \\==\\.-.  - ,-.//==/_,  ,  - \\  \n"
        << "                               `--`\\==\\- \\  |==|   .=.     | \n"
        << "                                    \\==\\_ \\ |==|_ : ;=:  - | \n"
        << "                                    |==|- | |==| , '='     | \n"
        << "                                    |==|, |  \\==\\ -    ,_ /  \n"
        << "                                    /==/ -/   '.='. -   .'   \n"
        << "                                    `--`--`     `--`--''     \n"
        << endl;

    util.delay(2000);

    cout << Bred;
    cout << "       ,--.--------.     ,----.          ,-.--, ,--.--------.   .=-.-.  ,---.      \n"
        << "      /==/,  -   , -\\ ,-.--` , \\.--.-.  /=/, .'/==/,  -   , -\\ /==/_ /.--.'  \\     \n"
        << "      \\==\\.-.  - ,-./|==|-  _.-`\\==\\ -\\/=/- /  \\==\\.-.  - ,-./|==|, | \\==\\-/\\ \\    \n"
        << "       `--`\\==\\- \\   |==|   `.-. \\==\\ `-' ,/    `--`\\==\\- \\   |==|  | /==/-|_\\ |   \n"
        << "            \\==\\_ \\ /==/_ ,    /  |==|,  - |         \\==\\_ \\  |==|- | \\==\\,   - \\  \n"
        << "            |==|- | |==|    .-'  /==/   ,   \\        |==|- |  |==| ,| /==/ -   ,|  \n"
        << "            |==|, | |==|_  ,`-._/==/, .--, - \\       |==|, |  |==|- |/==/-  /\\ - \\ \n"
        << "            /==/ -/ /==/ ,     /\\==\\- \\/=/ , /       /==/ -/  /==/. /\\==\\ _.\\=\\.-' \n"
        << "            `--`--` `--`-----``  `--`-'  `--`        `--`--`  `--`-`  `--`         \n"
        << endl;
    cout << normal;

    util.delay(2500);


    util.slowRead("Welcome to my poorly made text-based adventure game! It will most likely be horribly written\n");
    util.slowRead("and hard to follow or control, but I mean, that's definitely part of the intended experience.\n\n");
    cout << Bnormal; util.slowRead("TUTORIAL\n"); cout << normal;
    util.slowRead("I know text based adventures are pretty self-explanatory, but I'm saying this all anyway.\n");
    util.slowRead("For each event you encounter, you will be given a list of numbered choices. Simply respond\n");
    util.slowRead("with the number of whichever one of the listed choices you wish to make.\n\n");
    util.slowRead("P.S. If at any point (after you choose a name) you want to view your inventory,\n");
    util.slowRead("just type \'Inventory\' (not case sensitive).\n\n");
}//intro

