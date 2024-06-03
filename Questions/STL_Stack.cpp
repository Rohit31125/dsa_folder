#include<iostream>
#include<stack>
using namespace std;
int main(){

    // Works on LIFO Fashion

    stack<string> s;
    s.push("Rohit");
    s.push("Dilip");
    s.push("Baruah");

    s.top(); //Shows the last(top) element of the task
    s.pop();
    s.size();
    s.empty();  

}