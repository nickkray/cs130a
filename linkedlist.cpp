#include "linkedlist.h"


//public methods

template <typename item>
void linkedlist<item>::add(item li){
    node* currentNode = new node;
    currentNode->data = li;
    if (count > -1){
        currentNode->next = first;
        currentNode->prev = last;
        last->next = currentNode;
        last = currentNode;
        count++;
    }
    else if (count == -1){
        first = currentNode;
        first->next = currentNode;
        first->prev = currentNode;
        last = currentNode;
        last->next = currentNode;
        last->prev = currentNode;
        count = 0;
    }
    
    
    
    template <typename item>
    void linkedlist<item>::removeAt(int index){
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
    item linkedlist<item>::findAt(int index){
        node* currentNode = first;
        if (index <= count && index > -1){
            int i = 0;
            while(i < index){
                currentNode = currentNode->next;
                i++;
            }
        }
        
        return currentNode->data;
    }
    
    
    template <typename item>
    item linkedlist<item>::findAt(int index){
        node* currentNode = first;
        if (index < 0 ) index =count +1 + index;
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
    item linkedlist<item>::First(){
        return first->data;
    }
    
    template <typename item>
    item linkedlist<item>::Last(){
        return last->data;
    }
    
    
    template <typename item>
    int linkedlist<item>::count(){
        return count;
    }
    
    
    template <typename item>
    void linkedlist<item>::clear(){
        node* currentNode = first;
        while(count > -1){
            node* tmp = currentNode;
            currentNode = currentNode->next;
            delete tmp;
            count--;
        }
    }
    
    
    template <typename item>
    linkedlist<item>::~linkedlist(){
        if (count > -1){
            clear();
        }
    }
