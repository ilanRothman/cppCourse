
#include <cstdio>
#include <iostream>


using namespace std;
//implementation of the generic map. to use this, it is needed that the
// "<" and the "==" operators are implemented for the key data type used.

//constructor
template<class T1, class T2>
Map<T1, T2>::Map() {
    head = current = NULL;
    nodeCount = 0;
}


//adding new item to map.
template<class T1, class T2>
void Map<T1, T2>::insert(T1 key, T2 val) {
    current = head;
    node *item = new node;
    item->key = key;
    item->value = val;
    item->next = NULL;
    if (head == NULL || item->key < head->key) { // first car.
        item->next = head;
        head = item;
        current = head;
        this->nodeCount++;
        return;
    }
    while (current->next != NULL && current->next->key < item->key) {
        current = current->next;
    }
    item->next = current->next;
    current->next = item;
    this->nodeCount++;
}

//finds the correct key and returns the value.
template<class T1, class T2>
T2* Map<T1, T2>::find(T1 key) {
    current = head;
    while(current!= NULL){
        if(current->key == key){
            return *current->value;
        }
    }
    return NULL;

}

//for removing a node from the map.
template<class T1, class T2>
void Map<T1, T2>::remove(T1 key) {
    node* temp = head;
    node* prev = NULL;
    if(temp!= NULL && temp->key == key){ //only one node and removing it.
        temp = head == NULL;
        this->nodeCount--;
        return;
    }
    while(temp!=NULL&& temp->key != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL){ //key not found.
        return;
    }
    prev->next = temp->next;
    delete temp;
}
//delete the map.
template<class T1, class T2>
void Map<T1, T2>::clear() {
    current = head;
    node* next = NULL;
    while(current!=NULL){
        next = current->next;
        delete current;
        current = next;
    }
    this->head = NULL;
    this->nodeCount = 0;
}

//printing out the map: key value.
template<class T1, class T2>
void Map<T1, T2>::print() {
    current = head;
    while(current!=NULL){
        cout << current->key << " " << current->value<<endl;
        current = current->next;
    }

}
//updates the values of the keys if changes.
template<class T1, class T2>
void Map<T1, T2>::updateValue(T1 key, T2 newValue) {
    current = head;
    while(current!= NULL){
        if(current->key == key){
            current->value = newValue;
            return;
        }
        current = current->next;
    }
}
//getter
template<class T1,class T2>
int Map<T1,T2>::getNodeCount() const {
    return nodeCount;
}


