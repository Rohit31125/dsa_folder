// gcd lcm relation  is lcm(a,b) * gcd(a,b)  = a*b

#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
    if(a<b){
        b=b-a;
    }
    if(b<a){
        a=a-b;
    }
    }
    return a;
}
int main(){

    int a,b;
    cout<<"Enter the Two numbers you want to find the gcd"<< endl;
    cin>>a;
    cin>>b;

    int answer = gcd(a,b);
    cout<<"The answer is " << answer;

    return 0;
}