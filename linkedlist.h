#ifndef _linkedlist_h
#define _linkedlist_h

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
    item First() const;
    item Last() const;
    
    int countNodes() const;
    void add(item li);
    void removeAt(int index);
    item findAt(int index) const;
    void clear();
    
    int find(item li) const;
    item* returnEverything() const;
    
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
item* linkedlist<item>::returnEverything() const{
    int len=countNodes();
    item* arr[len];
    node* currentNode = first;
    int index=0;
    if(currentNode){
        while(currentNode->next){
            arr[index]= new item(currentNode->data);
            index++;
            currentNode=currentNode->next;
        }
        return arr[len];
    }else{
        return nullptr;
    }
}

template <typename item>
int linkedlist<item>::find(item li) const{
    node* currentNode = first;
    int index=0;
    while(currentNode->next){
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
        first->prev = currentNode;
        last = currentNode;
        last->next = currentNode;
        last->prev = currentNode;
        count = 1;
    }
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
item linkedlist<item>::findAt(int index) const{       //find at index
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


template <typename item>
item linkedlist<item>::First() const{     //first item
    return first->data;
}

template <typename item>
item linkedlist<item>::Last() const{      //last item
    return last->data;
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
