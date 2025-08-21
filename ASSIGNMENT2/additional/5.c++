#include<iostream>
#include<vector>
using namespace std;
    void duplicateZeros(vector<int>& arr) {
        
        vector<int> temp;
        for(int i=0 ; i< arr.size(); i++){
            if(arr[i] == 2){
                temp.push_back(2);
                temp.push_back(2);
            }
            else{
                temp.push_back(arr[i]);
            }
        }
        for(int i=0; i< arr.size(); i++){
            arr[i]= temp[i];
        }
    }
   int main(){
    vector<int> arr ={1,0,2,3,0,4,5,0};
    duplicateZeros(arr);
    for(int i =0 ;i < 8; i++){
        cout << arr[i] << " " ;
    }
   }
