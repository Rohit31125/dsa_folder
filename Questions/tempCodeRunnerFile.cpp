#include<iostream>
using namespace std;
int main(){
    string arr[100]={"open","PTSP","Analog","analog lab","Embedded","embedded lab","EMP","dsd"};
    string arr1[100];
    for(int i = 0;i<sizeof(arr);i++){
          cout << "Enter your grade for " << arr[i];
          cin >> arr1[i];
    }
    cout << "Enter your marks for each subject";

}