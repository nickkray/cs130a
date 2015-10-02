#include "linkedlist.h"
//public methods

template <typename item>
void linkedlist<item>::add(item li){        //add item
    node* currentNode = new node;
    currentNode->data = li;
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
        first->prev = currentNode;
        last = currentNode;
        last->next = currentNode;
        last->prev = currentNode;
        count = 1;
    }
    
    
    
    template <typename item>
    void linkedlist<item>::removeAt(int index){     //remove at index
        if (index <= count){
            node* currentNode = last;
            for (int i = 0; i <= index; i++){
                currentNode = currentNode->next;
            }
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
            delete currentNode;
            count--;
        }
    }
    
    
    template <typename item>
    item linkedlist<item>::findAt(int index){       //find at index
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
    }
    
    
    linkedlist<item>::First()
    template <typename item>
    item linkedlist<item>::First(){     //first item
        return first->data;
    }
    
    template <typename item>
    item linkedlist<item>::Last(){      //last item
        return last->data;
    }
    
    
    template <typename item>
    int linkedlist<item>::count(){      //count that shit
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
