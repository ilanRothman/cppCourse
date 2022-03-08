#ifndef METROMAP_CAR_H
#define METROMAP_CAR_H
#include <string>
using namespace std;


class Car {

    private:
        string name;
        int pollutionFactor;
        unsigned int junctionNum;
public:


public:
     /*the big three are implemented here because I am using pointers as part of
        the class data types (car* next) and will be adding and moving round car objects, also because this is
        a base class there is need of a virtual destructer.
        so I didn't want to rely on the defaults that the compiler makes */

        //constructors
        Car();
        Car(int junctionNum,std::string name);
        /*copy constructor*/
        Car(const Car &temp);
        virtual ~Car();

    /*assignment operator overloading*/
        Car &operator=(const Car &other);
        Car * next; //holds the next car object in junction.

        /*getters and setters*/
        unsigned int getJunctionNum() const;

        virtual int WhereTo(int roads);

        virtual int getPollutionFactor() const;

        const string &getName() const;

        void setJunctionNum(int junctionNum);

        Car *getNext() const;

        void setNext(Car *next);

};




#endif //METROMAP_CAR_H
