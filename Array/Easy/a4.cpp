#include<bits/stdc++.h>
using namespace std;

// return the length of longest subarray with sum k (all +ve);
// subarray is contigious part of element inside array;


// brute sol;
int brute (int arr[] , int n , int k){    // tc = O(n*n); sc = O(1)
    int length = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        // int l = 0;
        for(int j = i; j<n; j++){
            sum+= arr[j];
            // if(sum < k){
            //     sum = sum + arr[j];    // this will work but this have a flow for 0 and negative no's;
            //     l++;
            // }
            // else break;
            if (sum == k) length = max(length , j - i + 1 );
        }
        // if (sum == k) length = max(length , l);
    }
    return length;
}

// better sol;
int better(int arr[] , int n , int k){   // (tc = O(nlogn) n for running loop n times and log n for performing fun like insertions and find); sc = O(n)
    map <int , int> prefixsum;           // if we use unordered map in place of map then tc = O(n) as all fun in unordered map is of tc of O(1);
    int sum = 0;                        // but in worst case it can be O(n) so tc will be O(n*n) in worst case;
    int length = 0;
    for (int i = 0 ; i<n ; i++){
        sum += arr[i];
        if (sum == k){
            length = max(length , i+1 );
        }
        if (prefixsum.find(sum - k) != prefixsum.end() ){
            length = max(length , i - prefixsum[sum - k]  );
        }
        if(prefixsum.find(sum) == prefixsum.end()){
        prefixsum[sum] = i;
        }
    }
    return length;
}

// optimal sol;
int optimal(int arr[] , int n, int k){  // tc = O(2n); sc = O(1);
    int right = 0;
    int left = 0;
    int length = 0;
    int sum = arr[0];
    while(right < n){ 
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if (sum == k){
            length = max(length , right - left +1);
        }
        right++;
        if(right < n){
            sum += arr[right];
        }
    }
    return length;
}

// return the length of longest subarray with sum k 

// brute will be same as for all +ve only
// better not exist
// better sol of all +ve is the optimal sol for array contaning -ve , 0 , +ve we cant optimise any other sol for it;
int main(){
    int arr[] = {1 , 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 0;

    cout << "Longest subarray length with sum " << k << " is: " << optimal(arr, n, k) << endl;
    return 0;
}