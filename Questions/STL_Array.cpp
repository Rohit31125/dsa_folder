#include<iostream>
#include<array>

using namespace std;
int main(){
    int basic[3]={1,2,3};
    array<int,4> a ={1,2,3,4};

    int size = a.size();   // For Getting size of the array

    for(int i=0;i<a.size();i++){
        cout << a[i] << endl;
    } 
    cout << "Element at 2nd index" << endl;   
    cout << "Empty or not" << a.empty() <<endl;   // To read a specific element from an array
    cout << "First element " << a.front() << endl; // To get the first element of an array
    cout << "Last element " << a.back()<<endl; //To get the last 
}