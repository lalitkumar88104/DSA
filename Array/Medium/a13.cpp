#include<bits/stdc++.h>
using namespace std;

// count no of subarray sum equal to k;

// brute sol;

int brute (vector<int> arr , int target){                       // tc = O(n*n) ; sc = O(1)
    int n = arr.size();
    int count = 0;
    // all possible subarrays;
    for(int i = 0 ; i<n ; i++){
        int sum = 0;
        for(int j = i ; j< n ; j++){
            sum += arr[j];
            if(sum == target){
                count++;
            }
        }
    }
    return count;
}

// no better sol;

// optimal sol;
int optimal (vector<int> arr , int target){             // tc = O(n) ; sc = O(n)
    int n = arr.size();
    unordered_map<int , int> prefixsum;
    prefixsum[0] = 1;
    int sum = 0;
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        sum += arr[i];
        if(prefixsum.find(sum - target) != prefixsum.end()){                // this if statement is not much important because map will return 0 if the search element is not present in map so count will end up with adding 0 that dosent effect if element is not present;
            count += prefixsum[sum - target];
        }
        prefixsum[sum] += 1;
    }
        return count;
}

int main (){
vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    // Function call to find the result
    int cnt = optimal(nums, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}