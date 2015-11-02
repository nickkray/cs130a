#ifndef _linkedlist_h
#define _linkedlist_h

#include "WallPost.h"

static bool operator==(const WallPost& a1, const WallPost& a2) {
    return a1.getText()==a2.getText() && a1.getTime()==a2.getTime() && a1.getMood() == a2.getMood();
}


template <typename item>
class linkedlist{
private:
    struct node{
        node* prev;
        node* next;
        item data;
        node(item d): data(d){};
    };
    
    node* last;
    node* first;
    int count;
public:
    
    linkedlist();
    ~linkedlist();
    item* First() const;
    item* Last() const;
    
    int countNodes() const;
    void add(item li);
    bool removeAt(int index);
    item* findAt(int index) const;
    bool addAt(int index, item li);
    void clear();
    
    bool setAt(int index, item li);
    
    int find(item li) const;
    
};

/*
 
 node* currentNode = first;
 if (index < 0 ) index =count + index;
 if (index <= count && index > -1){
 int i = 0;
 while(i < index){
 currentNode = currentNode->next;
 i++;
 }
 }
 
 return currentNode->data;
 
 */

template <typename item>
int linkedlist<item>::find(item li) const{
    node* currentNode = first;
    if(!currentNode){
        return -1;
    }
    int index=0;
    while(index<count){
        if(currentNode->data==li){
            return index;
        }
        index++;
        currentNode=currentNode->next;
    }
    return -1;
}


template <typename item>
void linkedlist<item>::add(item li){        //add item
    node* currentNode = new node(li);
    if (count > 0){
        currentNode->next = first;
        currentNode->prev = last;
        last->next = currentNode;
        last = currentNode;
        count++;
    }
    else if (count == 0){
        first = currentNode;
        first->next = currentNode;
        //first->prev = currentNode;
        last = currentNode;
        //last->next = currentNode;
        last->prev = currentNode;
        count = 1;
    }
}


template <typename item>
bool linkedlist<item>::addAt(int index, item li){       //add at index, returns if successful
    node* currentNode = first;
    if (index <= count+1 && index > 0){ // <count+2 works for 1<0+2 in case list is empty// only increment if index>1 otherwise we're at first
        int i = 0;
        while(i < index-1){ // go to one beforebefore the index we're looking for, since we add it before
            currentNode = currentNode->next;
            i++;
        }
    }else{
        return false;
    }
    if(index==1 && count == 0){ // place it when empty
        first = new node(li);
        last = first;
    }else if(index>1){ //place at 1 and there are atleast 2
        currentNode->prev->next= new node (li);
        currentNode->prev->next->next = currentNode->next;
        currentNode->prev = currentNode->prev->next;
    }else{ //trying to place it before 1 (so at 0)
        node* tmp = currentNode;
        first = new node(li);
        first->next = tmp;
        tmp->prev = first;
    }
    count++;
    return true;
}



template <typename item>
bool linkedlist<item>::removeAt(int index){     //remove at index,false if unsuccessful
    if(!first || index>=count){
        return false;
    }
    if (index <= count){
        node* currentNode = first;
        for (int i = 0; i <= index; i++){
            currentNode = currentNode->next;
        }
        if(currentNode->prev){
            currentNode->prev->next = currentNode->next;
        }
        if(currentNode->next){
            currentNode->next->prev = currentNode->prev;
        }
        if(index==0){ // if first, fix first
            first = currentNode->next;
        }
        if(index<count-1){ //if last, fix last
            last = currentNode->prev;
        }

        delete currentNode;
        count--;
    }else{
        return false;
    }
    return true;
}


template <typename item>
bool linkedlist<item>::setAt(int index, item li){       //set at index
    node* currentNode = first;
    if (index < 0 ) index =count + index;
    if (index <= count && index > -1){
        int i = 0;
        while(i < index){
            currentNode = currentNode->next;
            i++;
        }
    }else{
        return false;
    }
    currentNode->data = li;
    return true;
}

template <typename item>
item* linkedlist<item>::findAt(int index) const{       //find at index
    node* currentNode = first;
    if (index < 0 ) index =count + index;
    if (index <= count && index > -1){
        int i = 0;
        while(i < index){
            currentNode = currentNode->next;
            i++;
        }
    }//else{
    //    return nullptr;
    //}
    
    return &(currentNode->data);
}


template <typename item>
item* linkedlist<item>::First() const{     //first item
    return &(first->data);
}

template <typename item>
item* linkedlist<item>::Last() const{      //last item
    return &(last->data);
}


template <typename item>
int linkedlist<item>::countNodes() const{      //count that shit
    return count;
}


template <typename item>
void linkedlist<item>::clear(){     //clear that shit
    node* currentNode = first;
    while(count > 0){
        node* tmp = currentNode;
        currentNode = currentNode->next;
        delete tmp;
        count--;
    }
}


template <typename item>
linkedlist<item>::~linkedlist(){    //deconstructor
    if (count > 0){
        clear();
    }
}

template <typename item>
linkedlist<item>::linkedlist(){     //constructor
    count=0;
}


#endif
