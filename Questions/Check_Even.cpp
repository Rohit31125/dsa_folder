#include<iostream>
using namespace std;
bool isEven(int a){
    if(a&1){
        return 0;
    }
    return 1;
}

int main(){
    int ans;
    int num;
    cout << "Enter the number to check :- ";
    cin >> num;
    ans = isEven(num);
    if(ans==0){
        cout << "The Number is Odd";
    }
    else{
        cout << "The number is Even";
    }
}