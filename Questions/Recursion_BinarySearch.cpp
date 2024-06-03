#include<iostream>
using namespace std;
bool BinarySearch(int arr[],int s,int e,int key){

    if(s>e){
        return false;
    }
    int mid = s +(e-s)/2;
    if(arr[mid]==key){  
        return true;
        }
    if(arr[mid]<key){
        return BinarySearch(arr,mid+1,e,key);
    }
    else{
        return BinarySearch(arr,s,mid-1,key);
    }
}
int main(){
    int arr[6]={2,3,65,78,91,99};
    int size = 6;
    int key = 65;
    bool ans = BinarySearch(arr,0,5,key);
    if(ans){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
}