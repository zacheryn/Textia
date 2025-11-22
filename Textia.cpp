#include "locations.hpp"

int main()
{
	Locations::startingForest sf;
	std::shared_ptr<Utility> util = std::make_shared<Utility>();
	sf.setUtility(util);

	sf.visit();

	return 0;
}
