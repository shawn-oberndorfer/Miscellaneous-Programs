#include "OreValues.h"

std::vector<Ore> getOres() {
    return {
        Ore("Veldspar", {
            {"Tritanium", 400.0}
        }),
        Ore("Scordite", {
            {"Tritanium", 150.0},
            {"Pyerite", 110.0}
        }),
        Ore("Pyroxeres", {
            {"Pyerite", 90.0},
            {"Mexallon", 30.0}
        })

    };
}