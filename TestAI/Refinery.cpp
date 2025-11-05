#include "Refinery.h"

Refinery::Refinery(double efficiency)
    : efficiency(efficiency) {}

std::map<std::string, double> Refinery::refine(const Ore& ore) const {
    std::map<std::string, double> refined;

    //Get all yields from ore
    auto yields = ore.getAllYields();

    // Apply efficiency to each mineral
    for (const auto& [mineral, amount] : yields) {
        refined[mineral] = amount * efficiency;
    }

    return refined;
}

