#ifndef DORDEREDSET_H
#define DORDEREDSET_H
#include "dset.h"

class dOrderedSet : public dSet {
public:
	dOrderedSet();
	dOrderedSet(int [], size_type);
	void insert(int, size_type);
private:
};


#endif