#include<iostream>
using namespace std;

int main(){
    int n;
    cin>> n;
    int row = 1;
    while(row<=n){
        int col = 1;
        int value = row;
        while(col<=row){
            cout << value;
            value = value + 1;
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
    }

}


// Note

// TO solve the problem of Patterns occasionaly use the formula of n-j+1,i+j-1, or use the combination of 
//  n,j,1 and i