#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l;
    list<int> n(5,100);  
    l.push_back(2);
    l.push_front(3);
    l.erase(l.begin());   //we cannot erase all element directly,
                            //instead we have to iterate through whole list
    for(int i:l){
        cout << i<<endl;
    }
}