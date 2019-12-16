#include <iostream>
#include "weightedQU.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int size;
    
    cout << "Input number of size.\n";
    cin>>size;
    weightedQU wqu(size);
    wqu.unionTwo(1, 2);
    wqu.unionTwo(2, 3);
    wqu.unionTwo(4, 5);
    cout<<"Is 3 & 5 connected?\t"<<wqu.connected(3, 5)<<endl;
    cout<<"Is 1 & 3 connected?\t"<<wqu.connected(3, 1)<<endl;
    cout<<"root of 3 & its weight: "<<wqu.root(3)<<", "<<wqu.getWeight(wqu.root(3))<<endl;
    return 0;
}
