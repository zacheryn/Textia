#include <iostream>
#include "player.hpp"

using namespace Inventory;

constexpr inventory::inventory() noexcept
: util{ nullptr } {
}

inventory::inventory(const std::shared_ptr<Utility>& _util) noexcept
: util{ _util } {
}

[[nodiscard]] bool inventory::hasItem(const InventoryItems i) const noexcept {
	return inv[static_cast<std::size_t>(i)];
}

void inventory::giveItem(const InventoryItems i) noexcept {
	inv[static_cast<std::size_t>(i)] = true;
}

void inventory::printInventory() const noexcept {
	std::cout << Bnormal;
	util->slowRead("INVENTORY:\n------------------\n");
	std::cout << normal;
}