#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    //creation
    unordered_map<string,int> m;

    //insertion

    //1
    pair<string,int> p = make_pair("rohit",3);
    m.insert(p);

    //2
    pair<string,int> pair2("baruah",2);
    m.insert(pair2);

    //3
    m["myname"] = 1;

    //what will happen
    //it overwrites
    m["myname"] = 2;

    //search
    cout << m["myname"] <<endl;
    cout << m.at("rohit") <<endl;

    //changing the order of the m and .at changes the output,if reversed from given then it will throw error
    // m assigns the value but at finds not assigns
    cout << m["unknownkey"] <<endl;
    cout << m.at("unknownkey") <<endl;

    //size
    cout << m.size() <<endl;

    //to check presence 
    cout << m.count("baruah") <<endl;

    //erase
    m.erase("myname");
    cout << m.size() <<endl;

    //iterator

    unordered_map<string,int> :: iterator it =  m.begin();

    while( it !=m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
    


}