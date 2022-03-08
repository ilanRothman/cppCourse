#include <iostream>
#include <cstdlib>
#include "Simulator.h"

int main(int argc, char** argv) {
    if( argc != 3){
        cerr << "ERROR: Invalid input.";
    }
    ifstream metroFile(argv[1]);
    ifstream vehicleLocation(argv[2]);
    if (!(metroFile.is_open()) || !(vehicleLocation.is_open())) {
        cerr << "ERROR: Invalid input.";
        exit(1);
    }

    Simulator simulator(metroFile,vehicleLocation);
    simulator.start();




    return 0;



}


