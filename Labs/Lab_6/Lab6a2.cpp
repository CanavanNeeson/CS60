#include <iostream>
#include <cassert>
#include <string>

template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find);


template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high);

int main() {
 
    std::string alex = "alex";
    std::string king = "king";
    
    int a[] = {1, 2, 5, 2, 3, 7, 2};
    std::string b[] = {"hello", "water", "computer", "water", "chair", "water", "another"};
    int size = 7;
    
    std::cout << count_exact(a, size, 2) << std::endl;
    std::cout << count_range(a, size, 3, 10) << std::endl;
    std::cout << count_range(b, size, alex, king) << std::endl;
    
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

template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high) {     //T2 needs < and <= and >= and ++ and =, T1 needs == and <= and >= and =
    int counter = 0;
    assert(low<=high);
    for(T2 i=0; i<size; i++) {
        if(a[i] >= low && a[i] <= high) {
            counter++;
        }
    }
    return counter;
}