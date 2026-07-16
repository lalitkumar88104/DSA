#include<bits/stdc++.h>
using namespace std;

// constraints - n will be given; array have n-1 element ; array contain element from 1 to n; find that 1 missing no 
int missing(int arr[] , int n ){    // find missing no from 1 to n in size of n-1 array; tc worst case= O(n*n); sc = O(1);
    for(int i = 1 ; i <= n ; i++){
        int flag = 0 ;
        for(int j = 0 ; j<n-1 ; j++){
            if (arr[j] == i){
                flag = 1;
                break;
            }
        }
        if (flag == 0) return i;
    }
    return -1;
}

int brutemissing(int arr[] , int n){  // brute sol using array hashing for finding missing no; tc = O(2n); sc = O(n);
    int hash [n+1] = {0};
    for( int i = 0 ; i< n-1 ; i++){
        hash[arr[i]] += 1;
    }
    for(int i = 1 ; i<= n ; i++){
        if (hash[i] == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n-1];
    cout << "Enter " << n-1 << " elements (from 1 to " << n << " with one missing): ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    int result = brutemissing(arr, n);
    cout << "The missing number is: " << result << endl;
    return 0;
}