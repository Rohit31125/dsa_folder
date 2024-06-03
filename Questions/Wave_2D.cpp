// Print like a wave  - Coding Ninjas


#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;
    for (int col = 0; col < mCols; col++) {
        if (col & 1) {          // This is used because by and biwise operator ,odd gives 1 output and even gives 0 output;......See for yourself
            // odd no of column
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else {
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main() {
    // Your main code here
    return 0;
}
