#include<bits/stdc++.h>
using namespace std;

// best time for buy and sell the stock 
// no brute beeter;

int maxProfit (int arr[] , int n){
    int mini = arr[0];
    int maxi = 0;
    for(int i = 1 ; i < n ; i++){
        if (mini > arr[i]){
            mini = arr[i];
        }
        maxi = max(maxi , arr[i] - mini );
    }
    cout << maxi << " " << mini ;
    return maxi ;
}

int main(){
    int arr[] = {10 , 15 , 8 , 14, 6 , 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Profit: " << maxProfit(arr, n);
    return 0;
}