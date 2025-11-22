#include "locations.hpp"

using Locations::startingForest;

void startingForest::visit() noexcept {
	++numVisits;
	util->slowRead(description);
}