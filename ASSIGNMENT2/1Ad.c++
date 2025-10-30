#include<iostream>
using namespace std;

void pairfunction(int arr[], int k, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){  
            if(arr[j] - arr[i] == k || arr[i] - arr[j] == k){ 
                cout << "The pair is: (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }
}

int main() {
    int arr[5] = {1, 4, 1, 4, 5};
    pairfunction(arr, 3, 5);
    return 0;
}
