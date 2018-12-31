#include <iostream>
#include <cassert>

template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find);

int main() {
 
    int a[] = {1, 2, 5, 2, 3, 7, 2};
    int size = 7;
    
    std::cout << count_exact(a, size, 2) << std::endl;
    
    return 0;
}

template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find) {     //T2 needs < and ++ and =, T1 needs ==
    int counter = 0;
    for(T2 i=0; i<size; i++) {
        if(a[i] == find) {
            counter++;
        }
    }
    return counter;
}