// que - Maximum occuring character - GeeksforGeeks
#include<iostream>
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        
        for(int i = 0;i<str.size();i++){
            int number  = 0;
            char ch = str[i];
            
            number = ch - 'a';
            arr[number]++;
        }
        int maxi = -1 , ans = -1;
        for(int j = 0;j<26;j++){
            if(maxi < arr[j]){
                ans = j;
                maxi = arr[j];
            }
        }
        return ans + 'a';
    }

};
using namespace std;
int main(){
}