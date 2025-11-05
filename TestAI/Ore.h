#ifndef ORE_H
#define ORE_H

#include <string>
#include <map>

class Ore {
private:
    std::string name;
    std::map<std::string, double> mineralYields;

public:
    Ore(std::string name, std::map<std::string, double> yields);

    std::string getName() const;
    double getYieldFor(const std::string& mineral) const;
    std::map<std::string, double> getAllYields() const;
};

#endif