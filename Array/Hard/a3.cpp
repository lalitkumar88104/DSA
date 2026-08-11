#include<bits/stdc++.h>
using namespace std;

// Three sum -> return triplet which sum == 0 and triplet must not be repeted;

// brute 

vector<vector<int>> brute (vector<int> arr){                // tc = o(n*n*n) + (mlogn) ; sc = O(2m)
    int n = arr.size();
    set<vector<int>> ans;
    for(int i = 0 ; i<n-2 ; ++i){
        for(int j = i+1; j<n-1 ; ++j){
            for(int k = j+1; k<n ; k++){
                if (arr[i] + arr[j] + arr[k] == 0 ){
                    vector<int> temp = {arr[i] , arr[j] , arr[k]};
                    sort(temp.begin() , temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(ans.begin() , ans.end());
    return result;
}

// better


vector<vector<int>> better (vector<int> &arr){              // tc = (n*n*log(no o f elements in value)) why multiplyed because find will check aggrisevly for no of iterations and iterations is n*n; sc = O(3n)        // first set is storing hash value at max n elements and reused again same then we are storing triplets in set then vector so 2n for this 
    int n = arr.size();
    set<vector<int>> st;
    for(int i = 0; i<n; i++){
        set<int> value;
        for(int j = i+1; j<n ; j++){
            int third = -(arr[i] + arr[j]) ;
            // cout << third << " ";
            if(value.find(third) != value.end()){
                vector<int> temp = {arr[i] , arr[j], third};
                sort(temp.begin() , temp.end());
                st.insert(temp);
            }
            value.insert(arr[j]);
        }
    }
    vector<vector<int>> ans (st.begin() , st.end()) ;
    return ans;
}

// optimal

    vector<vector<int>> threeSum(vector<int>& nums) {           // tc = O(nlogn) + O(n*n); sc = o(1);
        int target = 0;
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1, k = n - 1;
                while (j < k) {
                    if (nums[i] + nums[j] + nums[k] < target) {
                        j++;
                    } else if (nums[i] + nums[j] + nums[k] > target) {
                        k--;
                    } else {
                        temp = {nums[i], nums[j], nums[k]};
                        result.push_back(temp);
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                }
            }
        }
        return result;
    }

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};


    vector<vector<int>> ans = better(nums);

    // Print the result
    for (auto& triplet : ans) {
        cout << "[";
        for (auto& num : triplet) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
