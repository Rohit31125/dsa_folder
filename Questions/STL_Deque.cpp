#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>  d;

    d.push_back(1);
    d.push_front(2);
    d.at(1);
    d.front();
    d.back();
    d.empty(); // checks if the array is empty or not
    d.erase(d.begin(),d.begin() +1); //have to specify the beginning and the end to erase the deque

}