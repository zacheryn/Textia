#pragma once

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "utility.hpp"
#include <memory>
#include <array>

namespace Inventory {
	enum class InventoryItems : std::size_t {
		Torch = 0,
		CellarKey = 1
	};

	class inventory {
	private:
		friend class Player;
		
		// Stores true when the player has the item of that index (index is determined from InventoryItems)
		std::array<bool, 2> inv{};

		std::shared_ptr<Utility> util;

		constexpr inventory() noexcept;

		inventory(const std::shared_ptr<Utility>& _util) noexcept;

	public:

		[[nodiscard]] bool hasItem(const InventoryItems i) const noexcept;

		void giveItem(const InventoryItems i) noexcept;

		void printInventory() const noexcept;

		void setUtility(const std::shared_ptr<Utility>& _util) noexcept;

		~inventory() = default;
	};
}

// Used to hold various information on the player
class Player {
private:

	std::shared_ptr<Utility> util;

	Inventory::inventory inv;

public:

	constexpr Player() noexcept
	: util{ nullptr }
	{}

	Player(const std::shared_ptr<Utility>& _util) noexcept
	: util{ _util }
	{}
};

#endif