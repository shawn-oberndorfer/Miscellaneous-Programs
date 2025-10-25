#include <iostream>

// Function Declarations
void   OreChoice(int&, int&, int&, int&, int&, int&, int&);
// Veldspar Functions
void   Veldspar(int&);
double VeldsparTri(int);
// Scordite Functions
void   Scordite(int&, int&);
double ScorditeTri(int);
double ScorditePye(int);

int main(){
    int totalTritanium = 0;
    int totalPyerite   = 0;
    int totalMexallon  = 0;
    int totalIsogen    = 0;
    int totalNocxium   = 0;
    int totalZydrine   = 0;
    int totalMegacyte  = 0;

    OreChoice(totalTritanium, totalPyerite, totalMexallon, totalIsogen, totalNocxium, totalZydrine, totalMegacyte);

    return 0;
}

void OreChoice(int& totalTritanium, int& totalPyerite, int& totalMexallon, int& totalIsogen, int& totalNocxium, int& totalZydrine, int& totalMegacyte){
    bool isValid = false;
    int oreChoice;
    do{
        std :: cout << "What ore would you like to reprocess? \n 1. Veldspar \n 2. Scordite \n" << std :: endl;
        std :: cin >> oreChoice;
        
        switch(oreChoice){
            case 1:
                Veldspar(totalTritanium);
                isValid = true;
                break;
            case 2:
                Scordite(totalTritanium, totalPyerite);
                isValid = true;
                break;
            default:
                std :: cout << "Not a valid choice. Please re-enter a valid choice." << std :: endl;
                isValid = false;
                break;
        }
    }while(isValid == false);
}

void Veldspar(int& totalTritanium){
    int totalVeldspar;
    std :: cout << "How much Veldspar is being reproccessed?" << std :: endl;
    std :: cin >> totalVeldspar;

    totalTritanium = VeldsparTri(totalVeldspar) + totalTritanium;
}

double VeldsparTri(int totalVeldspar){
    const int VeldsparTri = 400;
    double tritaniumInVeldspar;
    tritaniumInVeldspar = (totalVeldspar / 100.0) * VeldsparTri;
    return tritaniumInVeldspar;
}

void Scordite(int& totalTritanium, int& totalPyerite){
    int totalScordite;
    std :: cout << "How much Scordite is being reproccessed?" << std :: endl;
    std :: cin >> totalScordite;

    totalTritanium = ScorditeTri(totalScordite) + totalTritanium;
    totalPyerite   = ScorditePye(totalScordite) + totalPyerite;
}

double ScorditeTri(int totalScordite){
    const int ScorditeTri = 150;
    double tritaniumInScordite;
    tritaniumInScordite = (totalScordite / 100.0) * ScorditeTri;
    return tritaniumInScordite;
}

double ScorditePye(int totalScordite){
    const int ScorditePye = 110;
    double pyeriteInScordite;
    pyeriteInScordite = (totalScordite / 100.0) * ScorditePye;
    return pyeriteInScordite;
}
