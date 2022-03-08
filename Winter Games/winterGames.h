
#ifndef WINTERGAMES_H
#define WINTERGAMES_H
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class winterGames{
    private:
        int const dim; // dimension of each athlete score results vector.
        int maxAmount; // max amount of athletes
        int athleteCount; // the amount of athletes added so far.
        string* athletes; // vector of athletes
        double** scores; // matrix of scores. each row represents the athlete scores.

    public:
        winterGames(int dimension,int max_amount); // constructer

        virtual ~winterGames(); // destructor

        int getDimension() const {return dim;}; //getter

        int getAthleteCount() const {return athleteCount;}; // getter

        void addResult(); // adds new result to - updates athletes and scores.

        void prntAthlete(); // prints an athlete with his scores.

        void athleteAvg(int index); // prints the athletes average score.

        void athleteScores(); // prints all the athletes with his average score.

        int findName(); // returns the index of the athlete from the athlete array.

        void avgResuls(); // prints the average scores of each referee.

        void Covariance(); // prints the covariance.

        void start(); // starts the menu.


    };

//global function

void prntFloat(double num); // correct print format.
bool isNumber(const char* str);
bool checkLegalnumbers(int dimension, const string& str); //checks if the user input for the scores is correct.
int findIndex(string* athlete, const string& new_M , int athlete_count); // finds the index of the athlete if the athlete array.

#endif //WINTERGAMES_H
