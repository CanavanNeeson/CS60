#include <iostream>
#include <string>
#include <cassert>

template <typename T>
class npoint {
public:
    npoint();
    npoint(int num);
    npoint(T a[], int num);
    
    T get_item(int i);
    int get_size() {return n;};
    
private:
    int n;
    T arr[10];
    
};

int main() {
    
    int a[2] = {2, 6};
    npoint<int> n1(a, 2);
    
    std::string b[5] = {"Hello", "how", "are", "you", "today?"};
    npoint<std::string> n2(b, 5);
    
    std::cout << n1.get_item(0) << " " << n1.get_item(1) << std::endl;
    std::cout << n1.get_size() << std::endl;
    
    for(int i=0; i<5; i++) {
        std::cout << n2.get_item(i) << " ";
    }
    std::cout << n2.get_size() << std::endl;
    
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
T npoint<T>::get_item(int i) {
    assert(i>=0); assert(i<n);
    return arr[i];
}