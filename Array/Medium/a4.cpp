#include<bits/stdc++.h>
using namespace std;

// Maximum subarray sum 

// brute sol
int brute (int arr[] , int n){          // tc = O(n*n*n) ; sc =O(1);
    int maxi = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        for (int j = i ; j<n ; j++){
            int sum = 0;
            for(int k = i ; k<=j ; k++){
                sum += arr[k];
                maxi = max(maxi , sum);
            }
        }
    }
    return maxi;
}


// better sol
int better (int arr[] , int n){     // tc =O(n*n) ; sc = O(1);
    int maxi = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        int sum = 0;
        for (int j = i ; j<n ; j++){
                sum += arr[j];
                maxi = max(maxi , sum);
        }
    }
    return maxi;
}

// Kadane's algo : i dont care i will traverse the array and add evrey elemrnt but where ever sum < 0 i will make sum = 0 and star adding from there onwards;

// Kadane's Algorithm: Traverse the array while maintaining the current subarray sum. 
// If the current sum ever becomes negative, discard it (set it to 0) because carrying a negative sum can only reduce the sum of any future subarray.


// optimal
int optimal(int arr[] , int n){             //tc = O(n) ; sc = O(1);
    int sum = 0; 
    int maxi = INT_MIN;
    for (int i = 0 ; i<n ; i++){
        sum+= arr[i];
        maxi = max(maxi , sum);
        if (sum < 0){
            sum = 0;
        }
    }
    if(maxi < 0) maxi = 0;   // this is for when q demands explicitly that if there is no +ve value than return an empty array;
    return maxi;
}

// print the sub array with max sum
array <int,2> optimalsubarray(int arr[] , int n){             //tc = O(n) ; sc = O(1);
    int sum = 0; 
    int maxi = INT_MIN;
    int start = -1;
    int end = -1;
    int ansstart = -1;
    for (int i = 0 ; i<n ; i++){
        if (sum == 0){
            ansstart = i;
        }
        sum+= arr[i];
        if(sum > maxi){
            maxi = sum; 
            start = ansstart;
            end = i;
        }
        if (sum < 0){
            sum = 0;
        }
    }
    return {start , end} ;
}

int main(){
    int arr[] = {-2, -1, -3, 4, -1, -2, 1, 5, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray Sum = " << optimal(arr, n) << endl;
    array <int , 2> index = optimalsubarray(arr , n);
    cout << index [0] <<" "<< index[1] << endl;
    for (int i =  index[0]; i <= index[1] ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}