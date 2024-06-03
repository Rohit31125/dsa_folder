// only works on sorted arrays
// time complexity O(logn)
#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;       // not using the direct average formula to keep the input in integer range
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start = mid +1;
        }
        else{
            end = mid -1;
        }
        mid = (start +end)/2;
    }
    return -1;
}
int main(){
    int arr1[6]={3,7,34,56,68,71};
    int arr2[7]={1,11,34,43,67,91,99};
    int keyEven;
    int keyOdd;
    cout << "Enter the Even Array key";
    cin >> keyEven;
    cout << "Enter the Odd Array key";
    cin >> keyOdd;

    int evenSearch = binarySearch(arr1,6,keyEven);
    int oddSearch = binarySearch(arr2,7,keyOdd);
    cout << "Index of " << keyEven << " is " << evenSearch << endl;
    cout << "Index of " << keyOdd << " is " << oddSearch << endl;
}