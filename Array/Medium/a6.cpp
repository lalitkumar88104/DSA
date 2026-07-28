#include<bits/stdc++.h>
using namespace std;

// rearange array elements by sign : there will be n elements in which n/2 is +ve and n/2 is -ve
// rearange them in order that first +ve than -ve and so on

// brute sol
void brute (int arr[] , int n){    // tc = O(2n) ; sc = O(n);
    vector <int> positive;
    vector <int> negative;
    for (int i = 0 ; i < n ; i++){
        if (arr[i] >= 0){
            positive.push_back(arr[i]);
        }
        else {
            negative.push_back(arr[i]);
        }
    }
    for(int i = 0 ; i<n ; i++){
        if (i%2 == 0){
            arr[i] = positive[i/2];
        }
        else{
            arr[i] = negative[i/2];
        }
    }
}

// better will work only and only if there are even no of elements (ex n = 6,8,10) it will ot work fo odd (n = 3 , 5, 7)
// better sol;
void better(int arr[] , int n){   // tc = O(n) + O(2/n) ; sc = O (n);
    vector <int> positive;
    vector <int> negative;
    for(int i = 0 ; i< n ; i++){
        if (arr[i] >= 0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }
    for(int i = 0 ; i<n/2 ; i++){
        arr[2*i] = positive[i];
        arr[2*i+1] = negative[i];
    }
}

//optimal sol
void optimal(int arr[] , int n){
    
}

int main (){
    int arr[] = {3, 1, -2, 2, -5};
    int n = sizeof(arr) / sizeof(arr[0]);

    brute(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}