#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
bool isSafe(int row,int col,vector<vector<int>> &board,int val){
    int n =  board.size();
    //Three conditions
    //checking rows
    for(int i = 0;i<n;i++){
        if(board[i][col]==val){
            return false;
        }
         if(board[row][i]==val){
            return false;
        }
        if(board[3*(row/3)+ i/3][3*(col/3)+i%3]==val){
            return false;
        }
    

}
return true;
}
bool solve(vector<vector<int>> &board){
    int n = board.size();

    for(int row = 0;row<9;row++){
        for(int col = 0;col<9;col++){
            if(board[row][col]==0){
                for(int val = 1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        bool aagesolpossible = solve(board);
                        if(aagesolpossible){
                            return true;
                        }
                        else{
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}