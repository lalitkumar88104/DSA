#include<bits/stdc++.h>
using namespace std;

// Merge overlapping subintervals;

// brute force 

vector<vector<int>> brute(vector<vector<int>>& arr){                // tc = O(nlogn) + O(2n) ; sc = O(n)
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin() , arr.end());
    for(int i = 0 ; i<n ; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j = i+1; j<n ; j++){
            if(arr[j][0] <= end){
                end = max(end , arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start , end});
    }
    return ans;
}

//  optimal also can reffer strivers version that is also good;

    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {                // tc = O(nlogn) + O(n) ; sc = O(n);
        int n = arr.size();
        int n1 = arr[0].size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int x;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                temp = {arr[i][0], arr[i][1]};
                x = arr[i][1];
            } 
            else if (x >= arr[i][0]) {
                if (x < arr[i][1]) {
                    temp[1] = arr[i][1];
                    x = arr[i][1];
                }
            } 
            else {
                ans.push_back(temp);
                temp.clear();
                temp = {arr[i][0], arr[i][1]};
                x = arr[i][1];
            }
            if (i == n - 1) {
                ans.push_back(temp);
            }
        }

        return ans;
    }


// striver version;

        vector<vector<int>> striver(vector<vector<int>>& arr) {                // tc = O(nlogn) + O(n) ; sc = O(n);
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i<n ; i++){
            if(ans.empty() || ans.back()[1] < arr[i][0]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1] , arr[i][1]);
            }
        }
        return ans;
    }

int main(){

        vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};  // Example input
    
    // Output the merged intervals
    vector<vector<int>> result = brute(arr);
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}