#include <iostream>
#include "quick_union.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int size;
    
    cout << "Input number of size.\n";
    cin>>size;
    QU qu(size);
    qu.unionTwo(1, 2);
    qu.unionTwo(2, 3);
    qu.unionTwo(4, 5);
    cout<<"Is 3 & 5 connected?\t"<<qu.connected(3, 5)<<endl;
    cout<<"Is 1 & 3 connected?\t"<<qu.connected(3, 1)<<endl;
    return 0;
}
