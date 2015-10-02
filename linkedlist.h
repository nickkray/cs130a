#ifndef _linkedlist_h
#define _linkedlist_h

template <typename item>
class linkedlist{
private:
    struct node{
        node* prev;
        node* next;
        item data;
    };
    
    node* last;
    node* first;
    int count;
public:
    linkedlist();
    ~linkedlist();
    item First();
    item Last();
    
    int count();
    void add(item item);
    void removeAt(int index);
    item findAt(int index);
    void clear();
};
#endif
