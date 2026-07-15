#include<bits/stdc++.h>
using namespace std;

void left (int arr[] , int n){         // optimal sol for rotate array left by one no brute better required ;
    int temp = arr[0];
    for(int i = 1 ; i<n ; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

void

int main(){
int n ;
    cout << "enter the size of array : ";
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    left( arr ,n);
    for (int i = 0 ; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}