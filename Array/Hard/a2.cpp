#include<bits/stdc++.h>
using namespace std;

// Majority element 2 : 

// Brute force sol:

vector<int> brute(vector<int> arr){                 // tc = O(n * n); sc = O(1);
    vector<int> ans;
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        if(ans.empty() || ans[0] != arr[i] ){
            int count = 0;
            for(int j = 0; j<n ; j++){
                if(arr[i] == arr[j]) count++;
                if(count > n/3) {
                    ans.push_back(arr[i]);
                    break;
                }
            }
        }
         if (ans.size() == 2) break;
    }
    return ans;
}

// better;          -> using hashing;

vector<int> better(vector<int> &arr){           // tc = O(nlogn); sc = O(n)
    map <int , int> mpp;
    vector<int> result;
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){                 // tc = O(n log n)
        mpp[arr[i]]++;
    }
    for(auto it : mpp){                         // tc = O(n)
        if(it.second > n/3) result.push_back(it.first);
    }
    return result;
}

// better better 

vector<int> betterbetter(vector<int> &arr){          // tc = O(nlogn); sc = O(n)
    map <int , int> mpp;
    vector<int> result;
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] == n/3 +1){
            result.push_back(arr[i]);
        }
        if(result.size() == 2) break;
    }
    return result;
}


// optimal

vector<int> optimal (vector<int> &nums){ 
        int n = nums.size();
        int mv = (n / 3) + 1;
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                cnt2 = 1;
            } else if (nums[i] == ele1)
                cnt1++;
            else if (nums[i] == ele2)
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1)
                cnt1++;
            if (nums[i] == ele2)
                cnt2++;
        }
        vector<int> ans;
        if (cnt1 >= mv)
            ans.push_back(ele1);
        if (cnt2 >= mv)
            ans.push_back(ele2);
        return ans;
}

int main(){
    vector<int> arr = {2, 1, 1, 3, 1, 4, 2, 2};
    

    vector<int> ans = optimal(arr);
    
    // Print the majority elements found
    cout << "The majority elements are: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}