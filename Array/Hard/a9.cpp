#include <bits/stdc++.h>
using namespace std;

    // find number of inversions in an array

    //brute             // tc = O(n*n); sc = O(1);
    long long int brute(vector<int>&nums) {
    
    //size of the array 
    int n = nums.size();
    
    // Count the number of pairs:
    long long int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            /*if nums[i] is greater than 
            nums[j], increase countby 1.*/
            if (nums[i] > nums[j]) cnt++;
            
        }
    }
    
    //return the count of inversions
    return cnt;

    }


// optimal              // tc  = O(nlogn); sc = O(n);

    /* Merge function to count 
    inversions and merge sorted halves*/
    long long int merge(vector<int>& arr, int low, int mid, int high) {
        
        // Temporary array for merging
        vector<int> temp;
        
        // Starting indices of left and right halves
        int left = low;
        int right = mid + 1;

        // Count variable to count the pairs
        long long int cnt = 0;

        // Merge sorted halves into temp array
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                
                temp.push_back(arr[left]);
                left++;
                
            } 
            else {
                temp.push_back(arr[right]);
                
                // Count inversions
                cnt += (mid - left + 1);
                
                right++;
            }
        }

        // Copy remaining elements of left half
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements of right half
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        /* Copy elements from temp 
        array back to original array*/
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
        //return the count of inversions
        return cnt;
    }
    
    // Merge sort function to recursively sort and count inversions
    long long int mergeSort(vector<int>& arr, int low, int high) {
        long long int cnt = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            
            // Sort left half
            cnt += mergeSort(arr, low, mid);  
            
            // Sort right half
            cnt += mergeSort(arr, mid + 1, high); 
            
            // Merge and count inversions
            cnt += merge(arr, low, mid, high);  
        }
        return cnt;
    }
    
    // Function to find number of inversions in an array
    long long int optimal(vector<int>& nums) {
        
        // Size of the array
        int n = nums.size();

        // Count the number of pairs
        return mergeSort(nums, 0, n - 1);
    }


int main() {
    vector<int> nums = {5, 4, 3, 2, 1, 0};
    

    long long int result = optimal(nums);
    
    // Print the repeating and missing numbers found
    cout << "The number of inversions is: "
         << result << endl;
    
    return 0;
}