#include<iostream>
using namespace std;
void Sort(int *arr,int n){
    if(n==1 || n==0){
        return;
    }
    for(int i = 0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
        }
    }
    Sort(arr,n-1);

}
int main(){
    int arr[5]={3,6,4,8,2};
    Sort(arr,5);
    for(int i = 0;i<5;i++){
        cout << arr[i]<< " ";
    }
}