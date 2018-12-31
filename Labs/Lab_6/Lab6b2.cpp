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
    
private:
    int n;
    T arr[10];
    
};

template <typename T>
npoint<T> operator +(const npoint<T>& a, const npoint<T>& b);

template <typename T>
bool operator ==(const npoint<T>& a, const npoint<T>& b);

int main() {
    
    int a[2] = {2, 6};
    int c[2] = {3, 4};
    int d[2] = {3, 4};
    npoint<int> n1(a, 2);
    npoint<int> n3(c, 2);
    npoint<int> n4(d, 2);
    
    std::string b[5] = {"Hello", "how", "are", "you", "today?"};
    npoint<std::string> n2(b, 5);
    
    std::cout << (n1+n3).get_item(0) << " " << (n1 + n3).get_item(1) << std::endl;
    
    std::cout << (n1==n3) << " " << (n3==n4) << std::endl;
    
    return 0;
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

