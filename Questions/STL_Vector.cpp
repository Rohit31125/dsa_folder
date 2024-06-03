#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    vector<int> a(5,1);  //creates a vector a and initializes with 1(fills all element with a) 
    vector<int> last(a);  // copies a vector to last vector

    v.capacity();  //shows the capacity of vector v
    v.push_back(1);
    cout << "capacity"<<v.capacity()<<endl;
    v.push_back(2);
    cout << "capacity"<<v.capacity()<<endl;
    v.push_back(3);
    cout << "capacity"<<v.capacity()<<endl;
    v.push_back(4);
    cout << "capacity"<<v.size()<<endl; //Shows size
    v.at(2);  //reads the specific element
    v.front(); //first element
    v.back();  //last element
    v.pop_back();  //removes the last element
    v.clear(); // removes all the element but does not affect the capacity of the vector
}