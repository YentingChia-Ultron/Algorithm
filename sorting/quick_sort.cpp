#include <iostream>
#include <vector>
#include <stdlib.h>      //rand()
#include <time.h>        //srand()
using namespace std;

template<class T>
int partition(std::vector<T> &arr,int front, int end)
{
    int i=front-1;
    int pivot=arr[end];
    for(int j=front;j<end;j++)
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    i++;
    swap(arr[i], arr[end]);
    return i;
}
template<class T>
void quickSort(std::vector<T> &arr,int front, int end)
{
    if(front<end)
    {
        int pivot=partition(arr, front, end);
        quickSort(arr, front, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

template<class T>
void quickSort(std::vector<T> &arr)
{
    quickSort(arr,0,(int)arr.size()-1);
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
    quickSort(arr);
    cout<<"After sorting:\n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
