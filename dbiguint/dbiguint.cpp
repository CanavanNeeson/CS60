#include "dbiguint.h"
#include <iostream>
#include <cassert>
dbiguint::dbiguint(){
    data_ = new unsigned short[1];
	data_[0] = 0;
	capacity_ = 0;
}
    
dbiguint::dbiguint(const std::string & s){
    
    data_ = new unsigned short [s.length()];
    capacity_ = s.length();
	
    for (std::size_t a=s.length() - 1, d = 0; a>=1; a--, d++){
        data_[d]= s[a] - '0';
    }
    
    data_[s.length() - 1] = s[0] - '0';
}

dbiguint::dbiguint(const dbiguint& b){
	capacity_ = b.capacity();
	data_ = new unsigned short [capacity_];
	for (std::size_t i = 0; i < capacity_; i++)
		data_[i] = b[i];
}

std::size_t dbiguint::size() const {
	return capacity_;
}

void dbiguint::operator =(const dbiguint& b) {
	capacity_ = b.capacity();
	data_ = new unsigned short [capacity_];
	for (std::size_t i = 0; i < capacity_; i++)
		data_[i] = b[i];
}

// std::string dbiguint::toStdString() const{
// 	std::string t, s;
// 	for (std::size_t i = 0; i < capacity_; i++) {
// 		t += (static_cast<char>(data_[i]) + '0');
// 	}
// 	
// 	bool started = 0;
// 	for (std::size_t i = t.length() - 1; i > 0; i--) {
// 		if (!started) {
// 			if (t[i] != '0') {
// 				started = 1;
// 				s += t[i];
// 			}
// 		} else {
// 			s += t[i];
// 		}
// 	}
// 	s += t[0];
// 	
// 	return s;
// 	
// }

dbiguint::~dbiguint() {
	delete [] data_;
}

unsigned short dbiguint::operator [](std::size_t pos) const{
// 	assert(pos < capacity_);
    return data_[pos];
}
// 
int dbiguint::compare(const dbiguint & b) const {
	if (this == &b) return 0;
	std::size_t cap = (capacity_ > b.capacity()) ? capacity_ : b.capacity();
	for (std::size_t i = cap; i > 0; i--) {
		if (data_[i] > b[i]) 
			return 1;
		else if (data_[i] < b[i])
			return -1;
	}
	
	if (data_[0] > b[0])
		return 1;
	else if (data_[0] < b[0])
		return -1;
	else
		return 0;
}

bool operator <(const dbiguint& b1, const dbiguint& b2) {
	return (b1.compare(b2) == -1);
}

bool operator <=(const dbiguint& b1, const dbiguint& b2) {
	return (b1.compare(b2) < 1);
}

bool operator ==(const dbiguint& b1, const dbiguint& b2) {
	return (b1.compare(b2) == 0);
}

bool operator !=(const dbiguint& b1, const dbiguint& b2) {
	return (b1.compare(b2) != 0);
}

bool operator >=(const dbiguint& b1, const dbiguint& b2) {
	return (b1.compare(b2) > -1);
}

bool operator >(const dbiguint& b1, const dbiguint& b2) {
	return (b1.compare(b2) == 1);
}

std::ostream& operator <<(std::ostream& out, const dbiguint& b) {
	
	
	if (b.size() > 1) {
		bool started = 0;
		for (std::size_t i = b.size() - 1; i > 0; i--) {
			if (started)
				out << b[i];
			else {
				if (b[i]){
					started = 1;
					out << b[i];
				}
			}
		}
	}
	out << b[0];
	
	return out;
}
// 
void dbiguint::operator += (const dbiguint & b) {
	this->reserve(b.capacity() + 1);
	for (std::size_t i = 0; i < capacity_; i++) {
		data_[i] += b[i];
		if (data_[i] > 9) {
			if (i == capacity_ - 1) {
				std::cout << "dbiguint overflow!\n";
				exit(1);
			} else {
				data_[i] -= 10;
				data_[i + 1]++;
			}
		}
	}
}

void dbiguint::operator -= (const dbiguint & b) {
	if (b > *this) {
		std::cout << "dbiguint underflow! (" << *this << " -= " << b << ")"<< std::endl;
		return;
	} else if (this == &b) {
		delete [] data_;
		data_ = new unsigned short[1];
		data_[0] = 0;
		return;
	}
	for (std::size_t i = 0; i < capacity_; i++) {
		if(data_[i] >= b[i]) {
			data_[i] -= b[i];
		} else { //data_[i] < b[i]
			if (i == capacity_ - 1) {
				std::cout << "dbiguint underflow!\n";
				return;
			} else {
				std::size_t j = i + 1;
				while (data_[j] == 0) {//finds smallest place value with nonzero value
					if (j >= capacity_) {std::cout << "Error in dbiguint::-=\n"; exit(1);}
					j++;
				}
				data_[j]--;
				j--;
				while (j > i) {
					data_[j] = 9;
					j--;
				}
				data_[j] += 10;
				data_[j] -= b[i];
			}
		}
	}
	
	std::size_t leadidx = capacity_ - 1;
	while (!data_[leadidx]) {
		if (leadidx > 0)
			leadidx--;
		else break;
// 		std::cout << leadidx << std::endl;
	}
	this->reserve(leadidx + 1);
}


dbiguint operator + (const dbiguint & b1, const dbiguint & b2) {
	dbiguint b3;
	b3 += b1;
	b3 += b2;
	return b3;
}

dbiguint operator - (const dbiguint & b1, const dbiguint & b2) {
	if (b2 > b1) {std::cout << "dbiguint underflow! (" << b1 << " - " << b2 << ")"<< std::endl; return b1;}
	dbiguint ret = b1;
	ret -= b2;
	return ret;
}

void dbiguint::reserve(std::size_t new_capacity) {
	if (new_capacity < capacity_) {
		for (std::size_t i = capacity_; i < new_capacity; i++) {
			if (data_[i] != 0) {
				std::cout << "dbiguint reserve() failed!\n";
				return;
			}
		}
		unsigned short* newptr = new unsigned short [new_capacity];
		for (std::size_t i = 0; i < new_capacity; i++)
			newptr[i] = data_[i];
		delete [] data_;
		data_ = newptr;
		capacity_ = new_capacity;
	}
	else {
		unsigned short* newptr = new unsigned short [new_capacity];
		for (std::size_t i = 0; i < capacity_; i++) 
			newptr[i] = data_[i];
		for (std::size_t i = capacity_; i < new_capacity; i++) 
			newptr[i] = 0;
		
		delete [] data_;
		data_ = newptr;
		capacity_ = new_capacity;
	}
}

std::size_t dbiguint::capacity() const {
	return capacity_;
}






























