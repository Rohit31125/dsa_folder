#include<iostream>
using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int reverse(int arr[],int size){
    int start = 0;
    int end = size - 1;
    for(start=0;start<=end;start++){
        swap(arr[start],arr[end]);
        end--;
    }
    int ans = arr[size];
    return ans;
    
}

int main(){

    int arr1[6]={7,3,9,78,54,5};
    int arr2[5]={4,6,34,2,8};
    reverse(arr1,6);
    reverse(arr2,5);
    printarr(arr1,6);
    printarr(arr2,5);
}