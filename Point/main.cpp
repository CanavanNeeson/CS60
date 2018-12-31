#include "npoint.h"
using std::string;
using std::cout;
using std::endl;

int main() {
    
    int a[2] = {2, 6};
    int c[2] = {3, 4};
    int d[2] = {3, 4};
	int e[2] = {3, 5};
    npoint<int> n1(a, 2);
    npoint<int> n3(c, 2);
    npoint<int> n4(d, 2);
	npoint<int> n5(e, 2);
    
    string b[5] = {"Hello", "how", "are", "you", "today?"};
    npoint<string> n2(b, 5);
	npoint<string> n2copy = n2;
    
 	cout << n2copy.get_item(0) << ' ' << n2copy.get_item(1) << ' ' << n2copy.get_item(2) << ' ' << n2copy.get_item(3) << ' ' << n2copy.get_item(4) << endl;
	
    cout << (n1+n3).get_item(0) << ' ' << (n1 + n3).get_item(1) << endl;
    cout << (n1==n3) << " " << (n3==n4) << ' ' << (n4 == n4) << ' ' << (n4 == n5) << endl;
    
    return 0;
}