#include<bits/stdc++.h>
using namespace std;

// merge two sorted arrays without using extra space;
// there are two types :
// 1. sort and place it in nums1 and nums2 according to there size;
// 2. nums1 has size == n+m; sort both and merge it in single array nums1;

// brute 
// use extra space as merge sort;
    // Function to merge two sorted arrays nums1 and nums2
    void brute(vector<int>& nums1, int m, vector<int>& nums2, int n) {              // tc = O(m+n) ; sc = O(m+n);
        
        // Declare a 3rd array and 2 pointers:
        vector<int> merged(m + n);
        int left = 0;
        int right = 0;
        int index = 0;

        /* Insert elements from nums1 and nums2 into
        merged array using left and right pointers*/
        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                merged[index++] = nums1[left++];
            } else {
                merged[index++] = nums2[right++];
            }
        }

        // If right pointer reaches the end of nums2:
        while (left < m) {
            merged[index++] = nums1[left++];
        }

        // If left pointer reaches the end of nums1:
        while (right < n) {
            merged[index++] = nums2[right++];
        }

        /* Copy elements from merged array
        array back to nums1 and nums2*/
        for (int i = 0; i < m + n; i++) {
            nums1[i] = merged[i];
           if (i<m) nums1[i] = merged[i];
           else nums2[i-n] = merged[i];
        }
    }

// better;

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {              // tc = O(m+n logn) + O(m + n)  sc = O(1); 

        // Pointer for nums1 (end of valid elements)
        int left = m - 1;  
        
        // Pointer for nums2 (beginning of valid elements)
        int right = 0;    

        /* Swap the elements until nums1[left]
        is greater than nums2[right]*/
        while (left >= 0 && right < n) {
            
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--, right++;
            }
            //break out of loop if nums1[left] > nums2[right] 
            else 
               break;
        }

        // Sort nums1 from index 0 to m-1
        sort(nums1.begin() + 0, nums1.begin() + m);
        
        //Sort nums2 from start to end
        sort(nums2.begin(), nums2.end());

        // Put the elements of nums2 in nums1
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }
    }

// better2;


// using gap method derived from shell sorting which say that maintain gap and compare and swap and decrease gap by 2 after every iteration
// please refer video for better understanding
// Gap method (inspired by Shell Sort):
// Treat nums1 + nums2 as one virtual array.
// Compare elements gap positions apart, swap if needed,
// then keep reducing the gap until gap = 1.


    void better2(vector<int>& nums1, int m, vector<int>& nums2, int n) {         // tc = O (n+m(logn)) + (n+m) ; sc = O(1)
        int len =  n + m ;
        int gap = (len / 2) + ( len % 2);
        while(gap > 0){
            int left = 0;
            int right = left + gap ;
            while (right < len){
                if(left < m && right < m){
                    if(nums1[left] > nums1[right]){
                        swap(nums1[left] , nums1[right]);
                    }
                     left++ , right++;
                }
                else if(left < m && right >= m){
                    if(nums1[left] > nums2[right - m]){
                        swap(nums1[left], nums2[right - m]);
                    }
                    left++ , right++;
                }
                else
                {
                    if(nums2[left-m] > nums2[right -m]){
                        swap(nums2[left-m] , nums2[right - m]);
                    }
                    left++ , right++;
                }
                // ++left , ++right;
            } 
            if (gap == 1 ) return;

            gap = (gap/2) + gap%2;
        }
    }


    // optimal

    void optimal(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int len = nums1.size() - 1;
        int left = m-1;
        int right = n-1;
        while(left >= 0 && right >= 0){
            if(nums1[left] > nums2[right]){
                nums1[len] = nums1[left];
                --len , -- left;
            }
            else {
                nums1[len] = nums2[right];
                --len , --right;
            }
        }
        while (right >= 0){
            nums1[len] = nums2[right];
            len-- ; right--;
        }
    }


    // better1 & better2 are optimal sol for 1st type;

int main(){

    vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
    vector<int> nums2 = {-3, 1, 8};
    int m = 4, n = 3;


 optimal(nums1, m, nums2, n);

    // Output the merged arrays
    cout << "The merged arrays is:\n";
    cout << "nums1[] = ";
    for (int i = 0; i < m+n; i++) {
        cout << nums1[i] << " ";
    }
  
    cout << endl;

    return 0;
}