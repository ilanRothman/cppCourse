#ifndef METROMAP_MAP_H
#define METROMAP_MAP_H


template <class T1, class T2>
class Map{
    //big three: didn't find a need to implement big three. will rely on compiler.

    //node for hilding key and value.
    struct node
    {
        T1 key;
        T2 value;
        node* next;
    };

private:

    int nodeCount;
    node* current;
    node* head;


public:
        Map();
        //delete the map
        void clear();
        //add node to map
        void insert(T1 key,T2 val);
        //remove a node from the map.
        void remove(T1 key);
        void updateValue(T1 key,T2 newValue);
        //return the value of the given key.
        T2* find(T1 key);
        //return the node count in the map.
        int getNodeCount() const;

        void print();

    };


#include "Map_imp.h"
#endif //METROMAP_MAP_H
