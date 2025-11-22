#pragma once

#ifndef LOCATIONS_HPP
#define LOCATIONS_HPP

#include "utility.hpp"

#include <string>
#include <memory>

namespace Locations {

    // Base class for locations
    class location {
    protected:

        std::uint16_t numVisits{ 0 };
        std::shared_ptr<Utility> util{ nullptr };

    public:
        location() noexcept = default;

        // Activates any events necessary upon visiting a location
        virtual void visit() noexcept = 0;

        // Returns the number of times the player has visited the location
        [[nodiscard]] const std::uint16_t getNumVisits() const noexcept {
            return numVisits;
        }

        // Returns true if the player has visited the location
        [[nodiscard]] const bool isVisited() const noexcept {
            return numVisits > 0;
        }

        void setUtility(const std::shared_ptr<Utility>& _util) noexcept {
            util = _util;
        }

        [[nodiscard]] const std::shared_ptr<Utility>& getUtility() const noexcept {
            return util;
        }

        virtual ~location() = default;
    };


    // The clearing in a forest where the player first wakes up
    class startingForest final : public location {
    private:

        // The general description of a location that will almost always be given upon entering
        static constexpr std::string_view description = "This is the starting forest.\n\n";

    public:

        startingForest() noexcept = default;

        [[nodiscard]] static constexpr std::string_view getDesc() noexcept {
            return description;
        }

        void visit() noexcept override;

        ~startingForest() override = default;
    };

}

#endif // LOCATIONS_HPP