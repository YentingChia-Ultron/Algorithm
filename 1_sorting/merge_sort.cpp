#include <iostream>
#include <vector>
#include <stdlib.h>      //rand()
#include <time.h>        //srand()
#define MAX (999999)
using namespace std;

template<class T>
void merging(std::vector<T> &arr, int front, int mid, int end)
{
    int lid=0, rid=0;
    //array[front]~array[mid] => leftArr
    //array[mid+1]~array[end] => rightArr
    std::vector<T> leftArr(arr.begin()+front,arr.begin()+mid+1),
                    rightArr(arr.begin()+mid+1,arr.begin()+end+1);
    leftArr.push_back(MAX);
    rightArr.push_back(MAX);
    for(int i=front;i<=end;i++)
    {
        if(leftArr[lid]<=rightArr[rid])
        {
            arr[i]=leftArr[lid];
            lid++;
        }
        else
        {
            arr[i]=rightArr[rid];
            rid++;
        }
    }
}
template<class T>
void merge(std::vector<T> &arr, int front, int end)
{
    if(front<end)
    {
        int mid=(front+end)/2;
        merge(arr, front, mid);
        merge(arr, mid+1, end);
        merging(arr, front, mid, end);
    }
}
template<class T>
void mergeSort(std::vector<T> &arr)
{
    merge(arr,0,(int)arr.size()-1);
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
    mergeSort(arr);
    cout<<"After sorting:\n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
