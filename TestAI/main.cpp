#include <iostream>
#include "OreValues.h"
#include "Refinery.h"

int main() {
    auto ores = getOres();
    Refinery t1(0.50);
    
    // Display menu
    std::cout << "Available Ores:\n";
    for (size_t i = 0; i < ores.size(); ++i) {
        std::cout << i + 1 << ". " << ores[i].getName() << "\n";
    }

    // User chooses ore
    int choice;
    std::cout << "Choose an ore (1-" << ores.size() << "): ";
    std::cin >> choice;

    if (choice < 1 || choice > (int)ores.size()) {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    // User enters units
    int units;
    std::cout << "Enter number of units of " << ores[choice - 1].getName() << ": ";
    std::cin >> units;

    // Refine and display results
    auto refined = t1.refine(ores[choice - 1]);
    std::cout << "\nRefined " << units << " units of " << ores[choice - 1].getName() << ":\n";
    for (const auto& [mineral, amount] : refined) {
        std::cout << "  " << mineral << ": " << amount * units << "\n";
    }

    return 0;
}
