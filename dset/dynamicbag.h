#ifndef DYNAMICBAG_H
#define DYNAMICBAG_H

#include <cstdlib>
#include <algorithm>

class dynamicBag
{
public:
    typedef std::size_t size_type;

    // CONSTRUCTOR & DESTRUCTOR

    // default constructor
    // pre: none
    // post: creates an empty dynamicBag
    dynamicBag();

    // copy constructor  (NEW! Before we used the built-in one)
    // pre: none
    // post: creates a new dynamicBag which is a copy of the given one
    dynamicBag(const dynamicBag &);

	dynamicBag(int a[], int sz) {
		capacity_ = sz;
		used_ = sz;
		data_ = new int[capacity_];
		for (size_type i = 0; i < used_; i++) 
			data_[i] = a[i];
	}
	
	void insertAt(int, size_type);
	
    // pre: none    (NEW!  Our first destructor)
    // post: destroys this dynamicBag; needed because we are using
    //       dynamically allocated memory
    ~dynamicBag();

    // CONSTANT MEMBERS
    // pre: none
    // post: returns the number of elements in this dynamicBag
    size_type size() const;

    // pre: none
    // post: returns the number of times entry appears in this dynamicBag
    size_type count(int entry) const;
    
    //pre:  pos<capacity_
    //post:  returns the pos(th) item in the bag.
    int operator [](size_type pos) const;

    // MUTATING MEMBERS

    // pre: none
    // post: adds a copy of target to this dynamicBag
    void insert(int target);

    // pre: none
    // post: adds to this dynamicBag a copy of each element of b
    void operator += (const dynamicBag & b);

    // pre: none
    // post: if target appears in this dynamicBag, remove one copy and
    //       return true; else return false

    bool erase_one(int target);

    // pre: none
    // post: removes every copy of target in this dynamicBag and
    //       returns the number of elements removed
    size_type erase(int target);

    // pre: none  (NEW!  Before we used the built-in one)
    // post: makes this bag a copy of b
    void operator =(const dynamicBag &b);

private:
    int *data_;
    size_type capacity_;
    size_type used_;

    // INVARIANTS:
    //   data_ points a dynamically allocated array of size capacity_
    //   data_[0], data_[1], ..., data_[used_-1] store the elements
    //   of this dynamicBag
    //   we don't care about data_[used_], ..., data_[capacity_]


};

// pre: none
// post: returns the sum of a and b

dynamicBag operator +(const dynamicBag & a, const dynamicBag & b);



#endif // DYNAMICBAG_H
