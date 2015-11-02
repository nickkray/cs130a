#ifndef cs130a_list_h
#define cs130a_list_h

#include "linkedlist.h"
#include <cstring>

template <class T>
class List {
public:
    virtual bool insert (int pos, const T & item){return false;};
    /* Inserts the item right before position pos, growing the list by 1.
     pos must be between 0 and the current length of the list.
     (feel free return bool, if you want.) */
    virtual bool remove (int pos){return -1;};
    /* Removes the element at position pos, shrinking the list by 1.
     pos must be between 0 and the current length of the list minus 1. */
    
    virtual void set (int pos, const T & item){};
    /* overwrites position pos in the list with item.
     Does not change the length of the list.
     pos must be between 0 and the current length of the list minus 1. */
    
    virtual T * get (int pos) const{return NULL;};
    /* returns the item at position pos, not changing the list.
     pos must be between 0 and the current length of the list minus 1. */
    virtual int find(T item){return -1;};
    virtual int count() const{return -1;};
    virtual T& first() = 0;
    virtual T& last() = 0;
};


template <class T>
class llList : public List<T> {
private:
    linkedlist<T> list;
public:
    bool insert (int pos, const T & item);
    bool remove (int pos);
    void set (int pos, const T & item);
    T * get (int pos) const;
    int find(T item);
    int count() const;
    T& first();
    T& last();
};

template <class T>
int llList<T>::find(T item){
    return list.find(item);
}

template <class T>
int llList<T>::count() const{
    return list.countNodes();
}

template <class T>
T& llList<T>::first(){
    return *list.First();
}

template <class T>
T& llList<T>::last(){
    return *list.Last();
}

template <class T>
bool llList<T>::insert(int pos, const T & item){
    if(pos>0 && pos<=list.countNodes()+1){
        return list.addAt(pos, item);
    }
    return false;
}


template <class T>
bool llList<T>::remove(int pos){
    return list.removeAt(pos);
}

template <class T>
void llList<T>::set(int pos, const T & item){
    list.setAt(pos, item);
}

template <class T>
T * llList<T>::get(int pos) const{
    return list.findAt(pos);
}

template <class T>
class arrList : public List<T> {
private:
    size_t capacity = 8;
    T* items;
    int maxElement=-1;
public:
    arrList(int n){
        capacity = n;
        items = new T[capacity];
    }
    arrList(){
        items = new T[capacity];
    }
    bool insert (int pos, const T & item);
    bool remove (int pos);
    void set (int pos, const T & item);
    T * get (int pos) const;
    
    int find(T item);
    int count() const;
    T& first();
    T& last();
};


template <class T>
bool arrList<T>::insert(int pos, const T & item){
    if(maxElement==-1 && pos<capacity){
        maxElement = pos-1;
        items[pos-1] = item;
        return true;
    }
    if(pos>0 && pos<capacity){
        if(maxElement==capacity-1){ // if last is full, we can't increment it
            maxElement = capacity-1; // this will be our new maxElement (n+1)
            T* newArr = new T[capacity*2];
            capacity*=2;
            std::memcpy(newArr, items, capacity/2 * sizeof(T));
            delete[] items;
            items = newArr;
        }
        for(size_t i=maxElement+2;i>=pos;i--){
            items[i] = items[i-1];
        }
        items[pos-1] = item;
        maxElement++;
        return true;
    }
    return false;
}


template <class T>
bool arrList<T>::remove(int pos){
    if(pos>-1 && pos<=maxElement){
        for(int i=pos;i<maxElement;i++){
            items[i] = items[i+1];
        }
        maxElement--;
        if(maxElement<capacity/2 && capacity>8){ // if we can reduce capacity, do so
            T* newArr = new T[capacity/2];
            capacity/=2;
            std::memcpy(newArr, items, capacity * sizeof(T));
            delete [] items;
            items = newArr;
        }
        return true;
    }
    return false;
}

template <class T>
void arrList<T>::set(int pos, const T & item){
    if (pos > 0 && pos<capacity) {
        items[pos] = item;
    }
}

template <class T>
T * arrList<T>::get(int pos) const{
    return &items[pos];
}


template <class T>
int arrList<T>::find(T item){
    for(int i=0;i<maxElement;i++){
        if(items[i] == item){
            return i;
        }
    }
    return -1;
}

template <class T>
int arrList<T>::count() const{
    return maxElement+1;
}

template <class T>
T& arrList<T>::first(){
    return items[0];
}

template <class T>
T& arrList<T>::last(){
    return items[maxElement];
}





#endif
