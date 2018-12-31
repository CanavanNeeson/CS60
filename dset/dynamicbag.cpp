#include "dynamicbag.h"
#include <cassert>
#include <iostream>

dynamicBag::dynamicBag(){
    used_ = 0;
    capacity_ = 0;
    data_ = NULL;
}

dynamicBag::dynamicBag(const dynamicBag& b){//Copy constructor
    capacity_ = b.capacity_;
    used_ = b.used_;
    data_ = new int[capacity_];
    for(size_type i = 0; i<used_; i++)
        data_[i] = b.data_[i];

}


void dynamicBag::operator =(const dynamicBag &b){//because the built-in = just does data_ = b._data, so they share memory, which is bad!!
    if(this == &b){//b.this????????????????????????????
        return;
    }
    if(capacity_!=b.capacity_){
        capacity_ = b.capacity_;
        delete [] data_;//add
        this->data_ = new int[capacity_];//(*this).data_
    }
    used_ = b.used_;
    for(size_type i = 0; i<used_; i++)
        data_[i] = b.data_[i];
}

dynamicBag::~dynamicBag(){//deallocate memory when an object is destroyed
    delete [] data_;//MUST HAVE
    data_ = NULL;//rest is nice to have
    capacity_ = 0;
    used_ = 0;
}

dynamicBag::size_type dynamicBag::size() const{
 return used_;   
}

dynamicBag::size_type dynamicBag::count(int target) const{
    size_type count = 0;
    for(size_type i = 0; i<used_; i++){
     if(data_[i] == target)
         count++;
    }
    return count;
    
}

int dynamicBag::operator [](size_type pos) const {return data_[pos];}


void dynamicBag::insert(int target){
    if(used_==0 &&capacity_==0){
			int* newptr = new int[1];
		data_ = newptr;
		capacity_=1;
    }
    else if(used_==capacity_){
		int* newptr = new int[capacity_*2];
		for(size_type i = 0; i<capacity_; ++i){
			newptr[i] = data_[i];
		}
		delete [] data_;
		data_ = newptr;
		capacity_*=2;
    }
    data_[used_] = target;
    used_++;
}

void dynamicBag::insertAt(int item, size_type index) {
// 	assert(index < capacity_ + 1);
	
    if(used_==0 &&capacity_==0){
			int* newptr = new int[1];
		data_ = newptr;
		data_[0] = item;
		capacity_=1;
    }
    else if(used_==capacity_ + 1){
		int last_item = data_[used_ - 1];
		int* newptr = new int[capacity_*2];
		for(size_type i = 0; i<index; ++i){
			newptr[i] = data_[i];
		}
		for (size_type i = index + 1; i < capacity_; ++i){
			newptr[i] = data_[i - 1];
		}
		delete [] data_;
		data_ = newptr;
		data_[capacity_] = last_item;
		capacity_*=2;
    }
//     std::cout << "\n\n" << data_[index] << "\n\n";
    data_[index] = item;
	
    used_++;
}

bool dynamicBag::erase_one(int target){

    size_type i = 0; 
    while(data_[i]!=target && i<used_) i++;
    
    if(i==used_)
        return false;
    else{
        for(size_type j=i; j<used_-1; j++){
        data_[j] = data_[j+1];   
        }
        used_--;
        
        if(used_<=.25*capacity_){
            int* newptr = new int[capacity_/2];
            for(size_type i = 0; i<used_; ++i){
                newptr[i] = data_[i];
            }
            delete [] data_;
            data_ = newptr;
            capacity_/=2;
        }
        
        return true;
    }
}

void dynamicBag::operator += (const dynamicBag & b) {
	if (used_ + b.size() > capacity_) {
		capacity_ = used_ + b.size() + 1;
		int* newptr = new int[capacity_];
	
		for (size_type i = 0; i < used_; i++) {
			newptr[i] = data_[i];
		}
		delete [] data_;
		data_ = newptr;
	} 
	
	for (size_type i = 0; i < b.size(); i++) {
		used_++;
		data_[used_ - 1] = b[i];
	}
	
	
	assert(capacity_ >= used_);
}


dynamicBag::size_type dynamicBag::erase(int target){

    size_type count=0;
    while(erase_one(target)) count++;
    return count;
}







