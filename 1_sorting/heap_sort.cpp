#include <iostream>
#include <vector>
#include <stdlib.h>      //rand()
#include <time.h>        //srand()
using namespace std;


template<class T>
void sink(vector<T> &arr, int key, int size)
{
    while((2*key)<= size)
    {
        int j = 2*key;
        if((j<size)&&(arr[j]<arr[j+1])) j++;
        if(arr[key]>=arr[j]) break;
        swap(arr[key],arr[j]);
        key=j;
    }
}

template<class T>
void heapSort(vector<T> &arr)
{
    int size = arr.size();
    arr.insert(arr.begin(), 0);
    for(int k=size/2;k>=1;k--)
        sink(arr,k,size);
    while(size>1)
    {
        swap(arr[1], arr[size]);
        size--;
        sink(arr, 1, size);
    }
    arr.erase(arr.begin());
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
    heapSort(arr);
    cout<<"After sorting:\n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
