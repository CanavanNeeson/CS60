//Canavan Neeson. HW 3. biguint.cpp
#include "biguint.h"
#include <iostream>
#include <cassert>
biguint::biguint(){
    for (std::size_t i=0; i<CAPACITY; i++){
        data_[i]=0;
    }
}
    
biguint::biguint(const std::string & s){
    
    if (s.length()>CAPACITY){
		std::cout << "Length is greater than CAPACITY!\n";
        exit(1);
    }
       for (std::size_t i=0; i < CAPACITY; i++){
        data_[i]=0;
    }
    
    for (std::size_t a=s.length() - 1, d = 0; a>=1; a--, d++){
        data_[d]= s[a] - '0';
    }
    
    data_[s.length() - 1] = s[0] - '0';
}

biguint::biguint(const biguint& b){
	for (std::size_t i = 0; i < CAPACITY; i++)
		data_[i] = b[i];
}

biguint biguint::operator =(const biguint& b) {
	for (std::size_t i = 0; i < CAPACITY; i++)
		data_[i] = b[i];
}

std::string biguint::toString() const{
	std::string t, s;
	for (std::size_t i = 0; i < CAPACITY; i++) {
		t += (static_cast<char>(data_[i]) + '0');
	}
	
	bool started = 0;
	for (std::size_t i = t.length() - 1; i > 0; i--) {
		if (!started) {
			if (t[i] != '0') {
				started = 1;
				s += t[i];
			}
		} else {
			s += t[i];
		}
	}
	s += t[0];
	
	return s;
	
}

unsigned short biguint::operator [](std::size_t pos) const{
    return data_[pos];
}

int biguint::compare(const biguint & b) const {
	for (std::size_t i = CAPACITY - 1; i > 0; i--) {
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

bool operator <(const biguint& b1, const biguint& b2) {
	return (b1.compare(b2) == -1);
}

bool operator <=(const biguint& b1, const biguint& b2) {
	return (b1.compare(b2) < 1);
}

bool operator ==(const biguint& b1, const biguint& b2) {
	return (b1.compare(b2) == 0);
}

bool operator !=(const biguint& b1, const biguint& b2) {
	return (b1.compare(b2) != 0);
}

bool operator >=(const biguint& b1, const biguint& b2) {
	return (b1.compare(b2) > -1);
}

bool operator >(const biguint& b1, const biguint& b2) {
	return (b1.compare(b2) == 1);
}

std::ostream& operator <<(std::ostream& out, const biguint& b) {
	
	bool started = 0;
	for (std::size_t i = biguint::CAPACITY - 1; i >0; i--) {
		if (started)
			out << b[i];
		else {
			if (b[i]){
				started = 1;
				out << b[i];
			}
		}
	}
	out << b[0];
	
	return out;
}

void biguint::operator += (const biguint & b) {
	for (std::size_t i = 0; i < CAPACITY; i++) {
		data_[i] += b[i];
		if (data_[i] > 9) {
			if (i == CAPACITY - 1) {
				std::cout << "biguint overflow!\n";
				exit(1);
			} else {
				data_[i] -= 10;
				data_[i + 1]++;
			}
		}
	}
}

void biguint::operator -= (const biguint & b) {
	if (b > *this) {
		std::cout << "biguint underflow! (" << *this << " -= " << b << ")"<< std::endl;
		return;
	}
	for (std::size_t i = 0; i < CAPACITY; i++) {
		if(data_[i] >= b[i]) {
			data_[i] -= b[i];
		} else { //data_[i] < b[i]
			if (i == CAPACITY - 1) {
				std::cout << "biguint underflow!\n";
				return;
			} else {
				std::size_t j = i + 1;
				while (data_[j] == 0) {//finds smallest place value with nonzero value
					if (j >= CAPACITY) {std::cout << "Error in biguint::-=\n"; exit(1);}
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
}


biguint operator + (const biguint & b1, const biguint & b2) {
	biguint b3;
	b3 += b1;
	b3 += b2;
	return b3;
}

biguint operator - (const biguint & b1, const biguint & b2) {
	if (b2 > b1) {std::cout << "biguint underflow! (" << b1 << " - " << b2 << ")"<< std::endl; return b1;}
	biguint ret = b1;
	ret -= b2;
	return ret;
}
	
	
/*	
	if (b1 < b2) {
		std::cout << "biguint underflow! (" << b1 << " -= " << b2 << ")" << std::endl;
		return b1;
	} else {
		std::string s = b1.toString();
		biguint t(s);
		t -= b2;
		return t;
	}
}*/
































