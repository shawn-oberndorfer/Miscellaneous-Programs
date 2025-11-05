#include "OreValues.h"

std::vector<Ore> getOres() {
    return {
        Ore("Veldspar", {
            {"Tritanium", 4.0}
        }),
        Ore("Scordite", {
            {"Tritanium", 1.5},
            {"Pyerite", 1.1}
        }),
        Ore("Pyroxeres", {
            {"Pyerite", 0.9},
            {"Mexallon", 0.03}
        })

    };
}