#include "dorderedset.h"
#include <iostream>

dOrderedSet::dOrderedSet() : dSet() {}

dOrderedSet::dOrderedSet(int a[], size_type sz) : dSet() {
	//sorting array
	for (size_type i = 0; i < sz; i++) {
		for (size_type j = 0; j < sz; j++) {
			if (a[i] > a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	
	for (size_type i = sz - 1; i > 0; i--) {
		if (this->count(a[i]) == 0)
			this->dSet::insert(a[i]);
	}
	if (this->count(a[0]) == 0)
		this->dSet::insert(a[0]);
}
	
	
	
	
// 	this->dSet::insert(a[0]);
// 	for (size_type i = 1; i < sz; i++) {
// 		std::cout << this->count(a[i]) << '\n';
// 		if (this->count(a[i]) == 0) {
// 			std::cout << this->count(a[i]) << ' ';
// 			size_type lt = 0;
// 			for (size_type j = 0; j < i; j++)
// 				if ((*this)[j] < a[i])
// 					lt++;
// 			std::cout << lt << '\n';
// 			this->insertAt(a[i], lt);
// 		}
// 	}
// }
// 	
	
	

