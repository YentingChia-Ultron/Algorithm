#include <iostream>
#include <vector>
#include <stdlib.h>      //rand()
#include <time.h>        //srand()
using namespace std;


template<class T>
void insertionSort(std::vector<T> &arr)
{
    for(int i=1;i<arr.size();i++)
    {
        for(int j=i;j>0;j--)
            if(arr[j]<arr[j-1])
                swap(arr[j-1], arr[j]);
            else break;
    }
}


template<class T>
void swap(T &a, T &b)
{
    T tmp=a;
    a=b;
    b=tmp;
}

int main(int argc, const char * argv[]) {
    vector<int> arr;
    int size=0, min= 0, max = 0;
    cout<<"Enter the size and bound[min,max] of array:\n";
    cin>>size>>min>>max;
    srand((unsigned)time(NULL));
    for(int i=0;i<size;i++)
        arr.push_back(rand() % (max - min + 1) + min);
    cout<<"Oringinal array:\n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    insertionSort(arr);
    cout<<"After sorting:\n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
