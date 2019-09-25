#include <iostream>
#include <vector>
#include <stdlib.h>      //rand()
#include <time.h>        //srand()
using namespace std;

template<class T>
void shellSort(std::vector<T> &arr)   //improve of insertion sort
{
    int h=1;
    while(h<(arr.size()/3)) h=3*h+1;  //add gap as 3x+1
    while(h>=1)
    {
        for(int i=h;i<arr.size();i++)
        {
            for(int j=i;(j>=h)&&(arr[j]<arr[j-h]);j-=h)
                    swap(arr[j-h], arr[j]);
        }
        h=h/3;
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
    shellSort(arr);
    cout<<"After sorting:\n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
