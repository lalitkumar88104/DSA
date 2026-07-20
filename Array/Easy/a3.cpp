#include<bits/stdc++.h>
using namespace std;

// constraints - n will be given; array have n-1 element ; array contain element from 1 to n; find that 1 missing no 
int missing(int arr[] , int n ){    // brute sol for find missing no from 1 to n in size of n-1 array; tc worst case= O(n*n); sc = O(1);
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

int brutemissing(int arr[] , int n){  // better sol using array hashing for finding missing no; tc = O(2n); sc = O(n);
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

int optimalsummissing(int arr[] , int n){   // optimal sol for finding missing no using sum or mathematically; TC = O(n); SC = O(1)
int sum = 0;
for(int i = 0 ; i < n-1 ; i++){
    sum = sum +arr[i];
}
int missing = (n*(n+1) / 2) - sum;
return missing;
}

int optimalxormissing(int arr[] , int n){ // optimal sol for finding missing no using xor; tc = O(n); sc = O(1);
    int xor1 = 0;
    int xor2 = 0;
    for(int i =0 ; i<n-1 ; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ i+1;
    }
    xor1 = xor1 ^ n ;
    return xor1 ^ xor2;
}


//why xor is better:
// although both use same time complexity of O(n) but xor is better because let assume ther is value of n is 10^5
// so n(n+1)/2 will become approx 10^10 which will exceed the limit of int container and cause overflow condition
// to solve this we need larger data type which will take slight more space in memory to solve this we use XOR as 
// better option;



int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n-1];
    cout << "Enter " << n-1 << " elements (from 1 to " << n << " with one missing): ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    int result = optimalxormissing(arr, n);
    cout << "The missing number is: " << result << endl;
    return 0;
}