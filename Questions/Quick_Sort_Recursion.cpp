//homework - Why quick sort is better than merge sort?


#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
    int pivot = arr[s];
    int count = 0;

    for(int i=s+1;i<=e;i++){
        if(arr[i] <= pivot ){
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[pivotindex],arr[s]);
    int i = s;
    int j = e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex ){
            swap(arr[i++],arr[j--]);
        }
}
return pivotindex;
}
void Sort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    //For left side sorting
    Sort(arr,s,p-1);
    //For Right side sorting
    Sort(arr,p+1,e);
}
int main(){
    int arr[6]={3,2,78,54,98,34};
    int size = 6;
    Sort(arr,0,size - 1);
    for(int i = 0;i<size;i++){
        cout << arr[i] << " ";
    }
}