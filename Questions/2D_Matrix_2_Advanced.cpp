#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowindex = 0;
        int colindex = col -1;
        while(rowindex < row && colindex >=0){
            if(matrix[rowindex][colindex]==target){
                return 1;
            }
            else if(matrix[rowindex][colindex] < target){
                rowindex++;
            }
            else{
                colindex--;
            }
        }
        return 0;
    }
};
using namespace std;
int main(){
}