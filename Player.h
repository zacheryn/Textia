#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Utility.h"

enum class Items : std::size_t {
    Torch
};//Items


//Holds relavant data for the player
class Player {
private:
    const std::size_t NUM_ITEMS = 1;
    const std::string name;
    std::vector<Items> inv;
    Utility* util;


public:

    //Constructor
    //Takes in the player's name
    Player(const std::string& _name, Utility &_util) :
    name{ _name }, util{&_util} {
        inv.reserve(NUM_ITEMS);
    }

    //Outputs a const reference to the player's name
    const std::string& getName() {
        return name;
    }//getName;


    //Check if the player has a specified Item
    bool hasItem(const Items item) {
        auto it = std::find(inv.begin(), inv.end(), item);
        if (it == inv.end()) return false;
        return true;
    }//hasItem

    //Gives the player an item
    void giveItem(const Items item) {
        if (hasItem(item)) return;
        inv.push_back(item);
    }//giveItem

    //Takes an item from the player
    void takeItem(const Items item) {
        auto it = std::find(inv.begin(), inv.end(), item);
        if (it != inv.end()) inv.erase(it);
    }//takeItem

    //Gives a const reference to the player's inventory
    const std::vector<Items>& getInv() {
        return inv;
    }

    //Display the player's inventory
    void showInventory() {
        std::cout << Bnormal;
        util->slowRead("Inventory:\n");
        std::cout << normal;

        for (const Items item : inv) {
            switch (item) {
            case Items::Torch:
                util->slowRead("\tTorch\n");
            }
        }
    }
};//Player

#endif