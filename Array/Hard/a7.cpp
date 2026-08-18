
/*
        optimal sol is pending ;
*/

#include<bits/stdc++.h>
using namespace std;

// merge two sorted arrays without using extra space;

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

// optimal;



int main(){

    vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
    vector<int> nums2 = {-3, 1, 8};
    int m = 4, n = 3;



    brute(nums1, m, nums2, n);

    // Output the merged arrays
    cout << "The merged arrays is:\n";
    cout << "nums1[] = ";
    for (int i = 0; i < m+n; i++) {
        cout << nums1[i] << " ";
    }
  
    cout << endl;

    return 0;
}