#include<bits/stdc++.h>
using namespace std;

// count subarray with given xor k;

// brute force;

int brute (vector<int> &nums , int target){         // tc = O(n*n)  sc = O(1);
    int cnt = 0;
    int n = nums.size();
    for(int i = 0; i<n ; i++){
        long long xor1 = 0;
        for(int j = i; j<n; j++){
            xor1 = xor1 ^ nums[j];
            if(xor1 == target) cnt++;
        }
    }
    return cnt;
}

// optimal

    int subarraysWithXorK(vector<int>& nums, int k)                 // tc = O(nlogn) ; sc = O(n);
    {
        int n = nums.size(); 
        int xr = 0;
        map<int, int> mpp; 
        // setting the value of 0.
        mpp[xr]++;  // mpp[0] ++;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            // prefix XOR till index i:
            xr = xr ^ nums[i];

            // By formula: x = xr^k:
            int x = xr ^ k;

            // add the occurrence of xr^k to the count:
            cnt += mpp[x];

            // Insert the prefix xor till index i into the map:
            mpp[xr]++;
        }
        return cnt;
    }

int main(){
vector<int> a = {4, 2, 2, 6, 4}; 
    int k = 6; 

    // Function call to get the result
    int ans = brute(a, k);
  
    cout << "The number of subarrays with XOR k is: " << ans << "\n";
    return 0;
}