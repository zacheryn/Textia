#include "Utility.h"

void Utility::delay(const int timer) {
    Sleep(timer);
}//delay

void Utility::slowRead(const std::string& s) {
    for (const auto c : s) {
        std::cout << c << std::flush;
        delay(textSpeed);
    }
}//slowRead

void Utility::slowRead(const std::string& s, const int d) {
    for (const auto c : s) {
        std::cout << c << std::flush;
        delay(d);
    }
}//slowRead

void Utility::options() {
    std::string input;
    slowRead("Would you like to change any options such as text speed? (This will be your only chance without restarting)\n");
    slowRead("\t1. Yes\n");
    slowRead("\t2. No\n");
    std::cin >> input;
    while (input != "1" && input != "2") {
        slowRead("Please enter a \'1\' or a \'2\'\n");
        std::cin >> input;
    }

    //Player chose not to adjust settings
    if (input == "2") return;

    input.clear();
    //List options
    while(input != "4") {
        std::cout << Bnormal;
        slowRead("OPTIONS\n");
        std::cout << normal;

        slowRead("\t1. Text speed: ");
        if (textSpeed == 25) slowRead("Fast\n");
        else if (textSpeed == 50) slowRead("Normal\n");
        else if (textSpeed == 75) slowRead("Slow\n");
        else slowRead("Very slow\n");

        slowRead("\t2. Profanity filter: ");
        if (profanity) slowRead("Off\n");
        else slowRead("On\n");

        slowRead("\t3. Graphics: Pristine\n");

        slowRead("\t4. Done\n");

        //Text speed
        if (input == "1") {
            input.clear();
            while (input != "1" && input != "2" && input != "3" && input != "4") {
                std::cout << Bnormal;
                slowRead("TEXT SPEED\n");
                std::cout << normal;
                slowRead("\t1. Very slow\n", 100);
                slowRead("\t2. Slow\n", 75);
                slowRead("\t3. Normal", 50);
                slowRead("\t4. Fast", 25);
            }
            if (input == "1") textSpeed = 100;
            else if (input == "2") textSpeed = 75;
            else if (input == "3") textSpeed = 50;
            else textSpeed = 25;
            std::cout << std::endl;
            input.clear();
        }

        //Profanity filter
        if (input == "2") {
            input.clear();
            while (input != "1" && input != "2") {
                std::cout << Bnormal;
                slowRead("PROFANITY FILTER\n");
                std::cout << normal;
                slowRead("\t1. On\n");
                slowRead("\t2. Off\n");
            }
            if (input == "1") profanity = false;
            else profanity = true;
            std::cout << std::endl;
            input.clear();
        }

        //Graphics
        if (input == "3") {
            slowRead("...\n");
            delay(250);
            slowRead("...\n");
            delay(250);
            slowRead("Yeah I don't what you expected to see here.  This is a text based game afterall.\n\n");
        }
    }
}//options