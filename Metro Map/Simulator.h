
#ifndef METROMAP_SIMULATOR_H
#define METROMAP_SIMULATOR_H

#include <fstream>
#include "Metropolis.h"

using namespace std;

class Simulator{
private:
    Metropolis *metropolis;


public:

    /*big three: had no need for copy constructor and assignment operator*/

    virtual ~Simulator(); //destructor

    Simulator(ifstream & metFile, ifstream & vehicleFile);

    void start(); //starts simulator

    double** checkFirst(ifstream &metroFile, int *size_out);

    void checkSecond(ifstream &ifstream, int size);
};

#endif //METROMAP_SIMULATOR_H
