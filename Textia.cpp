#include "locations.hpp"

int main()
{
	Locations::startingForest sf;
	std::shared_ptr<Utility> util = std::make_shared<Utility>();
	sf.setUtility(util);

	Locations::intro i;
	i.setUtility(sf.getUtility());
	i.printTitle();

	sf.visit();

	return 0;
}
