#include<iostream>
#include<queue>
using namespace std;
int main(){
    // max_Heap
    priority_queue<int> maxi;

    //min_Heap
    priority_queue<int,vector<int>,greater<int> > mini;

    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(4);


    mini.pop();
    mini.empty();

}