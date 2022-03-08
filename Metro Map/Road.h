//
// Created by iroth on 12/24/2021.
//

#ifndef METROMAP_ROAD_H
#define METROMAP_ROAD_H

class Junction;
class Road {
    private:
        double length; //length of road.
        double pollution; //current pollution
        Junction* from; //road stating junction
        Junction* to; // road destination.
        Road* next; // next road which has same stating point.

    public:

        /*the big three: except the destructor the other two are implemented here because i am using pointers as part of
         the class data types so i didn't want to rely on the defaults that the compiler makes*/

        Road(Junction& from,Junction& to,double length);
        Road(const Road &temp);
        Road& operator=(const Road &other); /*assignment operator overloading*/
    /*getters and setters*/
        double getPollution() const;
        void addPollution(int pollutionFactor);
        void setNext(Road *next);
        const Junction &getFrom() const;
        Road *getNext() const;
        Junction &getTo();


    };



#endif //METROMAP_ROAD_H
