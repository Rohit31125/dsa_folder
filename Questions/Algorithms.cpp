#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v;

       binary_search(v.begin(),v.end(),6);


       lower_bound(v.begin(),v.end(),6);
       upper_bound(v.begin(),v.end(),6);


       int a =3;
       int b= 5;

       swap(a,b);

       string str ="abcd";

       reverse(str.begin(),str.end());

       rotate(v.begin(),v.begin()+1,v.end());
}