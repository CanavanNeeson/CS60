#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include <iostream>
#include "node.h"

template <class T>
class lbag
{
public:
    typedef T value_type;
    typedef std::size_t size_type;

    // pre: none
    // post: creates an empty lbag
    lbag();

    // pre: none
    // post: creates an lbag that is a copy of given lbag
    lbag(const lbag &);

    //Returns all memory to the runtime environment and sets head and tail to nullptr
    ~lbag();

    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    void operator =(const lbag &);

    //pre: none
    //post:  returns the number of nodes in the linked list
    size_type size() const;

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    size_type count(const T &) const;

    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    void insert(const T &);

    //pre: none
    //post:  our bag includes all of its elements, followed by all of the parameter bag's elements
    void operator +=(const lbag &);//homework

    //pre: none
    //post:  removes the first instance of the parameter value in the bag, if there is one.
    bool erase_one(const T &);//homework

    //pre: none
    //post:  removes all instances of the parameter value in the bag.
    size_type erase(const T &);//homework

    template <class T2>//Don't use class's type variable, because this is NOT part of the class
    friend std::ostream& operator <<(std::ostream& out, const lbag<T2> &);

private:
    node<T> *head, *tail;
};

template <class T>
lbag<T> operator +(const lbag<T> &, const lbag<T> &);


//------------------------------------------------------------------------


template <class T>
lbag<T>::lbag(){
head = nullptr;
tail = nullptr;
}


template <class T>
lbag<T>::lbag(const lbag<T> & b){
    head = tail = nullptr;
    list_copy(b.head, b.tail, head, tail);
}

template <class T>
lbag<T>::~lbag(){
list_clear(head, tail);
head = tail = nullptr;
}

template <class T>
void lbag<T>::operator =(const lbag<T> & b){
    list_clear(head, tail);
    head = tail = nullptr;
    list_copy(b.head, b.tail, head, tail);
}


template <class T>
typename lbag<T>::size_type lbag<T>::size() const{
    list_size(head);
    size_type count = 0;
    for(node<T>* p = head; p!=nullptr; p=p->link())
        count++;
    return count;
}


template <class T>
typename lbag<T>::size_type lbag<T>::count(const T & value) const{
    size_type count = 0;
    for(node<T>* p = head; p!=nullptr; p=p->link()){
        if(p->data()==value)
            count++;
    }
    return count;    
}

template <class T>
void lbag<T>::insert(const T & value){
    list_head_insert(head, tail, value);
}

template <class T>
bool lbag<T>::erase_one(const T & value) {
	node<T> *temp = head, *prevtemp = nullptr;
	while (temp != nullptr) {
		if (temp->data() == value) {
			if (temp == head) {
// 				std::cout << "H\n";
				head = head->link();
				delete temp;
			} /*else if (temp == tail) {
				std::cout << "T\n";
				prevtemp->set_link(nullptr);
				delete temp;
			} */else {
// 				std::cout << '*' << prevtemp << '*';
				prevtemp->set_link(temp->link());
				delete temp;
			}
			return true;
		} else {
			prevtemp = temp;
			temp = temp->link();
		}
	}
	return false;
}

template <class T>
lbag<int>::size_type lbag<T>::erase(const T & value) {
	size_type count = 0;
	while (this->erase_one(value))
		++count;
	return count;
}

template <class T>
void lbag<T>::operator +=(const lbag<T>& r) {
	node<T> *wtemp = tail, *rtemp = r.head;
	while (rtemp != nullptr) {
		wtemp->set_link(new node<T>(rtemp->data(), nullptr));
		rtemp = rtemp->link();
		wtemp = wtemp->link();
	}
}

template <class T>
lbag<T> operator +(const lbag<T> & r, const lbag<T> & l) {
	lbag<T> ret(r);
	ret += l;
	return ret;
}

template <class T>
std::ostream& operator <<(std::ostream& out, const lbag<T> & b){//Use << from linked list toolkit.  Problems?
	out<<b.head;
	return out;
}

// template <class T>



#endif // LBAG_H


















