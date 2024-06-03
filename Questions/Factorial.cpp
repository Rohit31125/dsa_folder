#include<iostream>

int factorial(int a){
    int fact = 1;
    for(int i = 1;i<=a;i++){
        fact = fact * i;
    }
    return fact;
}
int nCr(int n,int r){
    int ans;
    int num = factorial(n);
    int den = factorial (r) * factorial(n-r);

    return num/den;

}
using namespace std;

int main(){

    int n;
    int r;
    int answer;
    cout << "Enter the the value of n";
    cin >> n;
    cout << "Enter the value of r";
    cin >> r;
    cout << "Answer of the Factorial is "<< endl << nCr(n,r);

}