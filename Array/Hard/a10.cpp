#include<bits/stdc++.h>
using namespace std;

// Count reverse pairs; (i < j && a[i] > 2 * a[j]);

// brute force                      tc = O(n*n);   sc = O(1);

int brute (vector<int> &nums){
    int n = nums.size();
    int cnt = 0;
    for(int i = 0; i < n-1 ; i++){
        for(int j = i+1; j<n ; j++){
            if(nums[i] > 2* nums[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

// optimal sol;
int countpairs(vector<int> &nums, int low, int mid, int high){
    int count = 0;
    int right = mid +1;
    for(int i = low ; i <= mid; i++){
        while(right <= high && (long  long) nums[i] > 2LL * nums[right] ){
            ++right;
        }
        count += (right) - (mid +1);
    }
    return count;
}

void sort(vector<int> &nums, int low, int mid, int high){
    int left = low;
    int right = mid +1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.emplace_back(nums[left]);
            left++;
        }
        else{
            temp.emplace_back(nums[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.emplace_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.emplace_back(nums[right]);
        right++;
    }
    for(int i = 0 ; i < temp.size(); i++){
        nums[i+low] = temp[i];
    }
}

int merge(vector<int> &nums, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high - low) / 2;
    cnt += merge(nums, low, mid);
    cnt += merge(nums , mid+1, high);
    cnt += countpairs(nums, low, mid, high);
    sort(nums , low , mid , high);
    return cnt;
}

int optimal (vector<int> nums){
    return merge(nums, 0, nums.size()-1);
}
int main() {
    
    vector<int> nums = {6, 4, 1, 2, 2, 7}; 
    

    int cnt = optimal(nums); 
    
    cout << "The number of reverse pairs is: " << cnt << endl;
    return 0; 
}