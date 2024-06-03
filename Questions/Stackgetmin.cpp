#include <stack>
#include <limits.h>
using namespace std;

class SpecialStack {
    stack<int> s;
    int min;

public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            min = data;
        } else {
            if (data < min) {
                s.push(2 * data - min);
                min = data;
            } else {
                s.push(data);
            }
        }
    }

    void pop() {
        if (s.empty()) {
            return;
        }
        int curr = s.top();
        s.pop();
        if (curr < min) {
            min = 2 * min - curr;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }
        int curr = s.top();
        if (curr < min) {
            return min;
        } else {
            return curr;
        }
    }

    int getMin() {
        if (s.empty()) {
            return -1; // Return -1 if stack is empty
        }
        return min;
    }
};
