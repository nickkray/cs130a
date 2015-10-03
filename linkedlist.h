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
    item First() const;
    item Last() const;
    
    int count const();
    void add(item item);
    void removeAt(int index);
    item findAt const(int index);
    void clear();
};
#endif
