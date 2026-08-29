#include<bits/stdc++.h>
using namespace std;


// find missing and repeating no from 1 to n ;

// brute : classic linear search
vector<int> brute(vector<int> &arr){    // tc = O(n*n);     sc = O(1);
    int rep = -1 , miss = -1;
    int n = arr.size(); 
    for(int i = 1 ; i<=n ; i++){
        int cnt = 0 ;
        for(int j = 0 ; j<n ; j++){
            if( i == arr[j]) cnt++;
        }
        if (cnt == 0) miss = i ;
        else if (cnt == 2 ) rep = i;

        if(rep != -1 && miss != -1) break;

    }
    return {rep , miss};
}


// better : using hash arr;

vector<int> better(vector<int> &arr){           // tc = O(2n) ; sc = O(n);
    int n = arr.size();
    int hash[n+1] = {0} ;
    for(int i = 0 ; i<n ; i++){
        hash[arr[i]]++;
    }
    int rep = -1 , miss = -1;
    for(int i = 1 ; i <= n ; i++){
        if(hash[i] == 0) miss = i;
        else if(hash[i] == 2) rep = i ;
    }
    return {rep , miss};
}


// optimal1 ;

vector<int>  optimal1(vector<int> &arr){
    // x - y = sum - s;
    // x^2 - y^2 = sum2n - S2n;
    int n = arr.size();
    long long s = (n * ( n + 1 )) / 2;
    long long S2n = (n * (n+1) * (2*n + 1)) / 6;
    
    long long sum = 0;
    long long sum2n = 0;
    for(int i = 0 ; i<n ; i++){
        sum = sum += arr[i];
        sum2n += (long long)arr[i] * (long long)arr[i] ;
    }
    long long x = sum - s;
    long long y = sum2n - S2n;
    y = y/x;

    int val1 = (x+y)/2;
    int miss = (val1 - x);
    return{int(val1) , miss};

}

//   optimal 2

vector<int> optimal2 (vector<int> &a){
    
}


int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5 , 8};
    
    vector<int> result = optimal1(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}