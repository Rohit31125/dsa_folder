#include<iostream>
#include<stack>
using namespace std;
class Stack{
    //properties
    public:
        int *arr;
        int top;
        int size;
    // behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }
    void pop(int element){
        if(top>=0){
            top--;

        }
        else
            cout << "Stack Underflow" << endl;
    }
    int peak(){
        if(top>=0)

        return arr[top];

        else
         
        cout << "Stack is empty" << endl;
        
    }
    bool isempty(){
        if(top==-1)

        return true;

        else

        return false;

    }
};
int main(){
    Stack st(5);
    
    st.push(44);
    st.push(42);
    st.push(33);
    st.push(21);
    st.push(46);

    st.pop(33);
    st.pop(46);

    cout << st.peak();

}