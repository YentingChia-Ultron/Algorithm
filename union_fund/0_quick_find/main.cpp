#include <iostream>
#include "quick_find.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int size;
    
    cout << "Input number of size.\n";
    cin>>size;
    UF uf(size);
    uf.unionTwo(1, 2);
    uf.unionTwo(2, 3);
    uf.unionTwo(4, 5);
    cout<<"Is 3 & 5 connected?\t"<<uf.connected(3, 5)<<endl;
    cout<<"Is 1 & 3 connected?\t"<<uf.connected(3, 1)<<endl;
    return 0;
}
