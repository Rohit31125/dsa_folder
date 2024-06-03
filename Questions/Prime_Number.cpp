

#include<iostream>
using namespace std;
int isPrime(int a){
    for(int i = 2;i<a;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    int ans = isPrime(n);
    if(ans==0){
        cout << "Not a prime number";
    }
    else{
    cout << "It is a prime number";
    }
}