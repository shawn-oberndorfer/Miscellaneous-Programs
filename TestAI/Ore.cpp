// Ore.cpp
#include "Ore.h"

Ore::Ore(std::string name, std::map<std::string, double> yields)
    : name(name), mineralYields(yields) {}

// Gets ore names.
std::string Ore::getName() const {
    return name;
}

// Gets the yields of a specific minerals
double Ore::getYieldFor(const std::string& mineral) const {
    // If the mineral exists in the map, return its value
    auto it = mineralYields.find(mineral);
    if (it != mineralYields.end()) {
        return (*it).second;
    }
    // If not found return 0.0
    return 0.0;
}

//Return the whole map
std::map<std::string, double> Ore::getAllYields() const {
    return mineralYields;
}