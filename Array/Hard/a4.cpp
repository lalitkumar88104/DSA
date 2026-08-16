#include <bits/stdc++.h>
using namespace std;

    // 4 sum - function to find quadruplets having sum equal to target
    vector<vector<int>> brute (vector<int>& nums, int target) {             // tc = O(n^4) ; sc = O(2m)
        // Size of the array
        int n = nums.size(); 
        
        // Set to store unique quadruplets
        set<vector<int>> st;
        
        // Checking all possible quadruplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        // Calculate the sum of the current quadruplet
                        long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                        
                        // Check if the sum matches the target
                        if (sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            // Sort the quadruplet to ensure uniqueness
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        
        // Convert set to vector (unique quadruplets)
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // better;


    vector<vector<int>> better(vector<int>& nums, int target) {  // tc = (n*n*n*log(m))   sc = O(n) + O(2 no of quadruplets);
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0 ; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){
                set<int> value;
                for(int k = j+1; k<n ; k++){
                    long long sum = nums[i] + nums[j] + nums[k] ;
                    int fourth = target - sum;
                    if(value.find(fourth) != value.end()){
                        vector<int>temp = {nums[i] , nums[j] , nums[k] , fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    value.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // optimal 

    vector<vector<int>> optimal(vector<int>& nums, int target) {    // tc = O(n*n*n) sc = O(1);
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i<n-3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<n-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1; int l = n-1;
                while(k<l){
                    int sum = nums[i] + nums[j] + nums[k] + nums[l]; 
                    if(sum < target){
                        k++;
                    }
                    else if (sum > target){
                        l--;
                    }
                    else{
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                        result.emplace_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
        return result;
    }

    
int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    
    vector<vector<int>> ans = better(nums, target);
    
    // Print the result
    cout << "The quadruplets are: \n";
    for (auto& it : ans) {
        cout << "[";
        for (auto& ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    
    return 0;
}
