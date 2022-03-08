#include "Simulator.h"
#include "Metropolis.h"
#include "FamilyCar.h"
#include "SportsCar.h"
#include "LuxuryCar.h"
#include "Maserati.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;


/*Simulator constructor is used for checking both files and
     creating all details for program*/

Simulator::Simulator(ifstream& metroFile, ifstream &vehicleFile) {
    double **graph;
    int size, iter;
    string line, iterations;

    /*checking first file*/
    graph = checkFirst(metroFile, &size);


    metropolis = new Metropolis(graph, size); //calling constructor of Metropolis
    /*second file check and initial*/
    checkSecond(vehicleFile, size);



    cin >> iterations;
    for (unsigned int i = 0; i < iterations.size(); i++) {
        if (!isdigit(iterations[i])) {
            cerr << "ERROR: Invalid input."; // not an integer
            exit(1);
        }
    }
    stringstream iterNum(iterations);
    iterNum >> iter;
    metropolis->setIterations(iter); // setting the iterations amount
    metropolis->createRoads(); // creating all the roads.


}

/*starting simulation*/
void Simulator::start() {
    int junctionNum;


    int whereTo;
    for (int iter = 0; iter < metropolis->getIterations(); iter++) {
        for (int i = 0 ; i < metropolis->getVehicleCount(); i++){
            junctionNum = metropolis->getVehicle(i).getJunctionNum(); //location of car

            whereTo = metropolis->getVehicle(i).WhereTo(metropolis->getJunction(junctionNum-1).getRoadCount());
            if (whereTo == 0){
                continue;}
            metropolis->move(metropolis->getVehicle(i),whereTo);
        }
    }
    /*printing updated location and pollution*/
    metropolis->printMatrix();
    metropolis->printVehicles();

}

double** Simulator::checkFirst(ifstream &metroFile,int * size_out) {
    double** graph;
    string line;
    int size =0;
    int lineCount = 0;
    getline(metroFile, line); //checking for non-legal characters.
    for (unsigned int i = 0; i < line.size(); i++) {
        if (isdigit(line[i]) == false) {
            cerr << "ERROR: Invalid input.";
            exit(1);
        }
    }

    stringstream num(line);
    num >> size;
    graph = new double *[size]; //initializing the graph;
    for (int i = 0; i < size; i++) {
        graph[i] = new double[size];
    }

    while (getline(metroFile, line)) {
        double weight;
        stringstream w(line);

        for (int i = 0; i < size; i++) {
            w >> weight;
            if (i == lineCount) {
                if (weight != 0) { //diagonal must be all zeros.
                    cerr << "ERROR: Invalid input.";
                    exit(1);
                }
            }
            if (weight < 0) { //only non negative numbers allowed
                cerr << "ERROR: Invalid input.";
                exit(1);
            }
            graph[lineCount][i] = weight; //adding weight to graph

        }
        if (w.rdbuf()->in_avail() != 0) { //more than size amount of junctions
            cerr << "ERROR: Invalid input.";
            exit(1);
        }
        lineCount++;
    }

    if (lineCount != size) { //wrong amount of lines in matrix.
        cerr << "ERROR: Invalid input.";
        exit(1);
    }
    *size_out = size;
    return graph;



}

void Simulator::checkSecond(ifstream &vehicleFile, int size) {
    int lineCount = 1;
    string line;

    int beginning; // for getting location for where the details start.
    if (size < 10) {
        beginning = 2;
    } else if (size < 100) {
        beginning = 3;
    } else {
        beginning = 4;
    }
    while (getline(vehicleFile, line)) {
        string carName;
        string details = line.substr(beginning, line.size());
        stringstream det(details);

        Junction *newJunction = new Junction(lineCount,size); // calling juntion constructor with junction id
        while (det.rdbuf()->in_avail() != 0) {
            det >> carName;
            Car* newCar;
            if(carName[0] == 'F'){
                newCar = new FamilyCar(lineCount,carName); //calling vehicle constructor with car number and junction location.
            }
            else if(carName[0] == 'S'){
                newCar = new SportsCar(lineCount,carName); //calling vehicle constructor with car number and junction location.
            }
            else if(carName[0] == 'L'){
                newCar = new LuxuryCar(lineCount,carName); //calling vehicle constructor with car number and junction location.
            }
            else if(carName[0] == 'M'){
                newCar = new Maserati(lineCount,carName); //calling vehicle constructor with car number and junction location.
            }
            else{
                cerr << "ERROR: Invalid input."; //wrong car type.
                exit(1);
            }
            newJunction->addVehicle(*newCar); // adding the vehicle to corrent junction.
            metropolis->addVehicle(*newCar);
        }
        metropolis->addJunction(*newJunction, lineCount-1); // adding the junction to with the vehicles to the metropolis
        delete newJunction;
        lineCount++;
    }


    if (lineCount > size + 1) {
        cerr << "ERROR: Invalid input."; //to many lines
        exit(1);
    }

}

Simulator::~Simulator() {
    delete metropolis;

}





