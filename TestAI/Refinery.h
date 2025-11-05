#ifndef REFINERY_H
#define REFINERY_H

#include "Ore.h"
#include <map>
#include <string>

class Refinery {
private:
    double efficiency;

public:
    Refinery(double efficiency);

    // Refine a single ore and return a map of refiner minerals
    std::map<std::string, double> refine(const Ore& ore) const;
};

#endif