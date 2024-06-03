#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main(){
    vector<string>arr={"open elective","3EL01(PTSP)","3EL02(Analog)","3EL04(embedded)","3EL06(emp)"};
    vector<string>arr1;
    vector<string>arr2={"3EL03(analog lab)","3EL05(embedded lab)"};
    vector<string> arr3;
    vector<string> arr4;
    for(int i = 0;i<arr.size();i++){
          cout << "Enter your grade for " << arr[i] << endl;
          string grade;
          cin >> grade;
          arr1.push_back(grade);
    }
    for(int i = 0;i<arr2.size();i++){
          cout << "Enter your grade for " << arr2[i] << endl;
          string grade;
          cin >> grade;
          arr3.push_back(grade);
    }
    
    int ans = 0;
    for(int i = 0;i<arr1.size();i++){
        if(arr1[i]=="AA" || arr1[i]=="aa" ){
            ans = ans + 10 * 3;
             
        }
        if(arr1[i]=="AB" || arr1[i]=="ab" ){
            ans = ans + 9 * 3;
             
        }
        if(arr1[i]=="BB" || arr1[i]=="bb" ){
            ans = ans + 8 * 3;
             
        }
        if(arr1[i]=="BC" || arr1[i]=="bc" ){
            ans = ans + 7 * 3;
             
        }
        if(arr1[i]=="CC" || arr1[i]=="cc" ){
            ans = ans + 6 * 3;
             
        }
        if(arr1[i]=="cd" || arr1[i]=="cd" ){
            ans = ans + 5 * 3;
             
        }
        if(arr1[i]=="dd" || arr1[i]=="dd" ){
            ans = ans + 4 * 3;
             
        }
    }
    
     for(int i = 0;i<arr3.size();i++){
        if(arr3[i]=="AA" || arr3[i]=="aa"){
            ans = ans + 10 * 1;
             
        }
        if(arr3[i]=="AB" || arr3[i]=="ab"){
            ans = ans + 9 * 1;
             
        }
        if(arr3[i]=="BB" || arr3[i]=="bb"){
            ans = ans + 8 * 1;
             
        }
        if(arr3[i]=="BC" || arr3[i]=="bc"){
            ans = ans + 7 * 1;
             
        }if(arr3[i]=="CC" || arr3[i]=="cc"){
            ans = ans + 6 * 1;
             
        }
        if(arr3[i]=="CD" || arr3[i]=="cd"){
            ans = ans + 5 * 1;
             
        }if(arr3[i]=="DD" || arr3[i]=="dd"){
            ans = ans + 4 * 1;
             
        }
       
     }
   
    string dsd;
     cout << "give your grade for 3EL42" << endl;
     cin >> dsd;
     arr4.push_back(dsd);
     for(int i = 0;i<arr4.size();i++){
        if(dsd=="AA" || dsd=="aa"){
            ans = ans + 10 * 4;
             
        }
        if(dsd=="AB" || dsd=="ab"){
            ans = ans + 9 * 4;
             
        }
        if(dsd=="BB" || dsd=="bb"){
            ans = ans + 8 * 4;
             
        }
        if(dsd=="BC" || dsd=="bc"){
            ans = ans + 7 * 4;
             
        }if(dsd=="CC" || dsd=="cc"){
            ans = ans + 6 * 4;
             
        }
        if(dsd=="CD" || dsd=="cd"){
            ans = ans + 5 * 4;
             
        }if(dsd=="DD" || dsd=="dd"){
            ans = ans + 4 * 4;
             
        }
       
     }
     
     float cpi;
     cout << "input your previous cpi" << endl;
     cin >> cpi;
     // cout << ans << endl;;
     float finalans = static_cast<float>(ans)/21;
   
     cout << "your total spi for this sem "<< finalans <<endl;

     float cumulative = (cpi * 77 + finalans * 21)/98;

     cout << " your cpi " << cumulative << endl;




}