#include<bits/stdc++.h>
using namespace std;

// sort an array of 0's , i's , 2's : array contains only 0 , 1, 2

// brute force sol
// use any sorting algo that you want for merge sort tc = O(nlogn) sc = O(n)

// better sol 
void better (int arr[] , int n){        // tc = O(2n); sc = O(1)
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i<n ; i++){
        if (arr[i] == 0) count0 ++;
        else if (arr[i] == 1) count1 ++;
        else count2 ++;
    }
    for(int i = 0 ; i < count0 ; i++){
        arr[i] = 0;
    }
    for(int i = count0 ; i < count0 + count1 ; i++){
        arr[i] = 1;
    }
    for(int i = count0 + count1 ; i < n ; i++){
        arr[i] = 2;
    }
}

// optimal sol: uses dutch national flag; 
// what's dutch national flag algo says : basically devide the array in no of parts that how many different elements you have
// int this there are 3 diff element so 
// 0 to low-1 : all are 0;
// low to mid-1 : all are 1;
// mid to high : all are unsorted;
// high+1 to n-1 : all are 2

// basically from 0 to mid-1 are sorted and high +1 to n-1 is sorted only unsorted part is mid to high identify it and place it on its boundary where its belong from;
void optimal (int arr[] , int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while (mid <= high){
        if(arr[mid] == 0){
            swap(arr[low] , arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else{
            swap(arr[mid] , arr[high]);
            high--;
        }
    }
}


int main(){
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // better(arr, n);
    optimal(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}