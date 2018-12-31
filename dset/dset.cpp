#include "dset.h"

dSet::dSet() : dynamicBag(){};

dSet::dSet(int a[], int sz) : dynamicBag(a, sz) {
	
// 	size_type newsize = 0;
// 	int *newarr = new int[size];
// 	size_type newarridx = 0;
	for (size_type i = 0; i < sz; i++) {
		size_type ct = this->count(a[i]);
		if (ct > 1) {
			for (size_type rmc = 0; rmc < ct; rmc++) {
				this->erase_one(a[i]);
				sz--;
			}
			i--;
		}
	}
}

void dSet::insert(int n) {
	if (count(n) > 0) return;
	
	dynamicBag::insert(n);
}
		