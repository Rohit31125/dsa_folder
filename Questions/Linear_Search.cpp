#include<iostream>
using namespace std;
bool search(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
        
    }
    return 0;
}

int main(){
    int arr[10] = {5,6,3,10,8,34,27,28,29};
    int key;
    cout << "Enter the key to search in the array";
    cin >> key;
    bool found = search(arr,10,key);
    if(found){
        cout << "Key is Present";
    }
    else{
        cout << "Key not Found";
    }
}