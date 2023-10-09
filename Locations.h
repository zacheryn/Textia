#pragma once

#ifndef LOCATIONS_H
#define LOCATIONS_H

#include "Player.h"
#include "Utility.h"

//Contains all information and functions regarding locations
class Locations {
private:

	Utility* util;

	//Used to determin if a player has been to the location before
	bool beenToSpawnForest = false;

public:

	//Constructor to get utilities
	Locations(Utility& _util) :
	util{ &_util } {}

	//Used to determine where the player currently is or where they came from
	enum class Locs {
		SpawnForest
	};

	//Holds the location and all relavant choices that can be made within the spawn forest
	void spawnForest();
};

#endif
