#include "Simulation.h"
#include <iostream>

using namespace std;

// Simulation* backup = nullptr;

int main(int argc, char** argv){
   // if(argc!=2){
   //     cout << "usage: simulation <config_path>" << endl;
  //      return 0;
  //  }
    // string configurationFile = argv[1];
    // Simulation simulation(configurationFile);
    // simulation.start();
    // if(backup!=nullptr){
    // 	delete backup;
    // 	backup = nullptr;
    // }
    //return 0;




// check stuff:
 Settlement tlv("Tel Aviv", CITY);

 // Access the object's properties using methods
    cout << "Name: " << tlv.getName() << endl;
    cout << "Type: " << (tlv.getType() == TOWN ? "Town" : "Other") << endl;

    // Call toString
    cout << tlv.toString() << endl;
}




