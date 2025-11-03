#include <iostream>

// Function Declarations
void   OreChoice(int&, int&, int&, int&, int&, int&, int&);
void   OreAmounts(int&, int&, int&, int&, int&, int&, int&);
// Veldspar Functions
void   Veldspar(int&);
double VeldsparTri(int);
// Scordite Functions
void   Scordite(int&, int&);
double ScorditeTri(int);
double ScorditePye(int);
// Plagioclase Functions
void   Plagioclase(int&, int&);
double PlagioclaseTri(int);
double PlagioclaseMex(int);
// Pyroxeres Functions
void   Pyroxeres(int&, int&);
double PyroxeresPye(int);
double PyroxeresMex(int);
// Omber Functions
void   Omber(int&, int&);
double OmberPye(int);
double OmberIso(int);
// Kernite Functions
void   Kernite(int&, int&);
double KerniteMex(int);
double KerniteIso(int);
// Jaspet Functions
void Jaspet(int&, int&);
double JaspetMex(int);
double JaspetNoc(int);

int main(){
    int totalTritanium = 0;
    int totalPyerite   = 0;
    int totalMexallon  = 0;
    int totalIsogen    = 0;
    int totalNocxium   = 0;
    int totalZydrine   = 0;
    int totalMegacyte  = 0;
    bool runAgain = true;
    bool isValid = false;
    char keepRunning;
    
    while(runAgain == true){
        isValid = false;
        OreChoice(totalTritanium, totalPyerite, totalMexallon, totalIsogen, totalNocxium, totalZydrine, totalMegacyte);
        while(isValid == false){
            std :: cout << "Would you like to calculate another ore? (y/n)" << std :: endl;
            std :: cin >> keepRunning;
            if(keepRunning == 'y' || keepRunning == 'Y'){
                runAgain = true;
                isValid = true;
            }
            else if(keepRunning == 'n' || keepRunning == 'N'){
                runAgain = false;
                isValid = true;
            } 
            else{
                isValid = false;
            }
        }
    }
    OreAmounts(totalTritanium, totalPyerite, totalMexallon, totalIsogen, totalNocxium, totalZydrine, totalMegacyte);
    return 0;
}

void   OreChoice(int& totalTritanium, int& totalPyerite, int& totalMexallon, int& totalIsogen, int& totalNocxium, int& totalZydrine, int& totalMegacyte){
    bool isValid = false;
    int oreChoice;
    while(isValid == false){
        std :: cout << "What ore would you like to reprocess? \n 1. Veldspar \n 2. Scordite \n 3. Plagioclase \n 4. Pyroxeres \n 5. Omber \n 6. Kernite \n 7. Jaspet \n" << std :: endl;
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
            case 3:
                Plagioclase(totalTritanium, totalMexallon);
                isValid = true;
                break;
            case 4:
                Pyroxeres(totalPyerite, totalMegacyte);
                isValid = true;
                break;
            case 5:
                Omber(totalPyerite, totalIsogen);
                isValid = true;
                break;
            case 6:
                Kernite(totalMexallon, totalIsogen);
                isValid = true;
                break;
            case 7:
                Jaspet(totalMexallon, totalNocxium);
                isValid = true;
                break;
            default:
                std :: cout << "Not a valid choice. Please re-enter a valid choice." << std :: endl;
                isValid = false;
                break;
        }
    }
}

void   OreAmounts(int& totalTritanium, int& totalPyerite, int& totalMexallon, int& totalIsogen, int& totalNocxium, int& totalZydrine, int& totalMegacyte){
    std :: cout << "Your total reprocessing yields for each mineral are as follows." << std :: endl;
    std :: cout << "Tritanium: " << totalTritanium << std :: endl;
    std :: cout << "Pyerite  : " << totalPyerite << std :: endl;
    std :: cout << "Mexallon : " << totalMexallon << std :: endl;
    std :: cout << "Isogen   : " << totalIsogen << std :: endl;
    std :: cout << "Nocxium  : " << totalNocxium << std :: endl;
    std :: cout << "Zydrine  : " << totalZydrine << std :: endl;
    std :: cout << "Megacyte : " << totalMegacyte << std :: endl;
}

void   Veldspar(int& totalTritanium){
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

void   Scordite(int& totalTritanium, int& totalPyerite){
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

void   Plagioclase(int& totalTritanium, int& totalMexallon){
    int totalPlagioclase;
    std :: cout << "How much Plagioclase is being reproccessed?" << std :: endl;
    std :: cin >> totalPlagioclase;

    totalTritanium  = PlagioclaseTri(totalPlagioclase) + totalTritanium;
    totalMexallon   = PlagioclaseMex(totalPlagioclase) + totalMexallon;
}

double PlagioclaseTri(int totalPlagioclase){
    const int PlagioclaseTri = 175;
    double tritaniumInPlagioclase;
    tritaniumInPlagioclase = (totalPlagioclase / 100.0) * PlagioclaseTri;
    return tritaniumInPlagioclase;
}

double PlagioclaseMex(int totalPlagioclase){
    const int PlagioclaseMex = 70;
    double mexallonInPlagioclase;
    mexallonInPlagioclase = (totalPlagioclase / 100.0) * PlagioclaseMex;
    return mexallonInPlagioclase;
}

void   Pyroxeres(int& totalPyerite, int& totalMexallon){
    int totalPyroxeres;
    std :: cout << "How much Pyroxeres is being reproccessed?" << std :: endl;
    std :: cin >> totalPyroxeres;

    totalPyerite  = PyroxeresPye(totalPyroxeres) + totalPyerite;
    totalMexallon  = PyroxeresMex(totalPyroxeres) + totalMexallon;
}

double PyroxeresPye(int totalPyroxeres){
    const int PyroxeresPye = 90;
    double pyeriteInPyroxeres;
    pyeriteInPyroxeres = (totalPyroxeres / 100.0) * PyroxeresPye;
    return pyeriteInPyroxeres;
}

double PyroxeresMex(int totalPyroxeres){
    const int PyroxeresMex = 30;
    double mexallonInPyroxeres;
    mexallonInPyroxeres = (totalPyroxeres / 100.0) * PyroxeresMex;
    return mexallonInPyroxeres;
}

void   Omber(int& totalPyerite, int& totalIsogen){
    int totalOmber;
    std :: cout << "How much Omber is being reproccessed?" << std :: endl;
    std :: cin >> totalOmber;

    totalPyerite  = OmberPye(totalOmber) + totalPyerite;
    totalIsogen  = OmberIso(totalOmber) + totalIsogen;
}

double OmberPye(int totalOmber){
    const int OmberPye = 90;
    double pyeriteInOmber;
    pyeriteInOmber = (totalOmber / 100.0) * OmberPye;
    return pyeriteInOmber;
}

double OmberIso(int totalOmber){
    const int OmberIso = 75;
    double isogenInOmber;
    isogenInOmber = (totalOmber / 100.0) * OmberIso;
    return isogenInOmber;
}

void   Kernite(int& totalMexallon, int& totalIsogen){
    int totalKernite;
    std :: cout << "How much Kernite is being reproccessed?" << std :: endl;
    std :: cin >> totalKernite;

    totalMexallon  = KerniteMex(totalKernite) + totalMexallon;
    totalIsogen  = KerniteIso(totalKernite) + totalIsogen;
}

double KerniteMex(int totalKernite){
    const int KerniteMex = 60;
    double mexallonInKernite;
    mexallonInKernite = (totalKernite / 100.0) * KerniteMex;
    return mexallonInKernite;
}

double KerniteIso(int totalKernite){
    const int KerniteIso = 120;
    double isogenInKernite;
    isogenInKernite = (totalKernite / 100.0) * KerniteIso;
    return isogenInKernite;
}
void   Jaspet(int& totalMexallon, int& totalNocxium){
    int totalJaspet;
    std :: cout << "How much Jaspet is being reproccessed?" << std :: endl;
    std :: cin >> totalJaspet;

    totalMexallon = JaspetMex(totalJaspet) + totalMexallon;
    totalNocxium = JaspetNoc(totalJaspet) + totalNocxium;
}

double JaspetMex(int totalJaspet){
    const int JaspetMex = 150;
    double mexallonInJaspet;
    mexallonInJaspet = (totalJaspet / 100.0) * JaspetMex;
    return mexallonInJaspet;
}

double JaspetNoc(int totalJaspet){
    const int JaspetNoc = 50;
    double nocxiumInJaspet;
    nocxiumInJaspet = (totalJaspet / 100.0) * JaspetNoc;
    return nocxiumInJaspet;
}