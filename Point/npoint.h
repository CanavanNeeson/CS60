#include <iostream>
#include <string>
#include <cassert>

template <typename T>
class npoint {
public:
    npoint();
    npoint(int num);
    npoint(T a[], int num);
    
    T get_item(int i) const;
    int get_size() const {return n;};
    npoint operator =(const npoint& np);
	//T must support =
	
	npoint operator +=(const npoint& np);
	//T must support =, +=
private:
    int n;
    T arr[10];
    
};

template <typename T>//T must support =, +
npoint<T> operator +(const npoint<T>& a, const npoint<T>& b);

template <typename T>//T must support =. !=
bool operator ==(const npoint<T>& a, const npoint<T>& b);

//-----------------------------

template <typename T>
npoint<T> npoint<T>::operator =(const npoint& np){
	n = np.get_size();
	for (int i = 0; i < 10; i++)
		arr[i] = np.get_item[i];
}

template <typename T>
npoint<T> npoint<T>::operator +=(const npoint& np) {
	int smallersize = (n > np.get_size()) ? n : np.get_size();
	for (int i = 0; i < smallersize; i++)
		arr[i] += np.get_item(i);
	
	if (n <= np.get_size()) {
		n = np.get_size();
		for (int i = smallersize; i < n; i++)
			arr[i] = np.get_item(i);
	}
}


template <typename T>
npoint<T>::npoint() {
    n = 0;
}

template <typename T>
npoint<T>::npoint(int num) {
    n = num;
}

template <typename T>
npoint<T>::npoint(T a[], int num) {
    n = num;
    for(int i=0; i<num; i++) {
        arr[i] = a[i];
    }
}

template <typename T>
T npoint<T>::get_item(int i) const {
    assert(i>=0); assert(i<n);
    return arr[i];
}

template <typename T>
npoint<T> operator +(const npoint<T>& a,const npoint<T>& b) {
    assert(a.get_size()==b.get_size());
    
    T newArray[a.get_size()];
    for(int i=0; i<a.get_size(); i++) {
        newArray[i] = a.get_item(i) + b.get_item(i);
    }
    
    npoint<T> newPoint(newArray, a.get_size());
    return newPoint;
}


template <typename T>
bool operator ==(const npoint<T>& a, const npoint<T>& b) {
	if (&a == &b) return true;
    if(a.get_size()!=b.get_size()) {
        return false;
    }
    
    for(int i=0; i<a.get_size(); i++) {
        if(a.get_item(i)!=b.get_item(i)) {
            return false;
        }
    }
    return true;
}









