#include "Locations.h"

void Locations::spawnForest() {
    if (!beenToSpawnForest) {
        beenToSpawnForest = true;
        util->slowRead("You stand up and take a look around.  For the most part you just see large pine\n");
        util->slowRead("trees in every direction, but just when you thought you were alone, you hear an old,\n");
        util->slowRead("decrepit voice behind you.  It's so sudden and shrill that you nearly jump out of\n");
        util->slowRead("your own skin.  The old man begins to speak to you.\n\n");
        util->slowRead("You shouldn't have come here ");
        std::cout << Bnormal;
        util->slowRead("BOY!");
        std::cout << normal;
        util->slowRead(" This is a dangerous place, but it is already too late for you.\n\n");
        util->slowRead("Then, just as quickly as he appeared, he disappears back into the forest.\n\n");

    }
    else {

    }
}//spawnForest