#include<iostream>
using namespace std;

int printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int swapAlternate(int arr[],int size){
    for(int i = 0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
    return arr[size];
}

int main(){
    int arr1[8]= {2,5,4,8,78,97,65,45};
    int arr2[7]={3,4,8,5,67,45,34};
    swapAlternate(arr1,8);
    swapAlternate(arr2,7);
    printArr(arr1,8);
    printArr(arr2,7);

}