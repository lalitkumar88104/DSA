#include<bits/stdc++.h>
using namespace std;
// Two sum : there are two varities of two sum 
// 1. return true or false is there any two elements present which sum is == target value;
// 2. its gauranted there are elements present then return the pos of that values whichs sum == target;


// brute sol;  tc = O(n*n); sc = O(1)
bool brute(int arr[] ,int n , int target){
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j< n ; j++){
            if (arr[i] + arr[j] == target ) return true;
        }
    }
    return false;
}

array <int , 2> brute2(int arr[] , int n , int target){
    array <int , 2> index;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n; j++){
            if(arr[i] + arr[j] == target) {
                index[0] = i;
                index[1] = j;
                return index;
            }
        }
    }
    return {-1 , -1} ;  // this will create tem array and return these values;
}

// better sol; tc = O(nlogn) ; sc = O(n) at worst case;
array <int , 2> better (int arr[] , int n , int target){    // this is the most ooptimal sol if you want indices
    map <int , int> value;
    for(int i = 0 ; i < n ; i++){
        if (value.find(target-arr[i]) != value.end()){
            return {i , value[target - arr[i]]} ;
        }
        value[arr[i]] = i;
    }
    return {-1 , -1};
}

bool better2 (int arr[] ,int n , int target){
    unordered_map<int , int > value;
    for(int i = 0 ; i <n ; i++){
        int complement = target - arr[i];
        if(value.find(complement) != value.end()){
            return true;
        }
        value[arr[i]] = i;
    }
    return false;
}

// optimal sol; (tc = O(nlogn) n for loop and nlogn for sorting so overall 2nlogn) sc = O(1);
bool optimal (int arr[] , int n , int target){
    sort(arr , arr+n);
    int left = 0; int right = n-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if(sum > target) right --;
        else left ++;
    }
    return false; 
}

// why this sol is not considered for this type of two sum :
// because in this we sort the array and the indices we return are not actually real position that are modified position
// therefor better sol is the most optimal sol for this type of two sum problem wher you need to return indices
// this is good if you want answer in yes or no or you care about elements you didn't need position of the elements;
array <int , 2> optimal2 (int arr[] , int n , int target){
    sort(arr , arr+n);
    int left = 0 ; int right = n-1;
    while (left < right){
        int sum = arr[left] + arr[right];
        if (sum == target) return {left , right};
        else if (sum > target) right --; 
        else left ++; 
    }
    return {-1 ,-1};
}

int main() {
    boolalpha;
    int arr[] = {2, 6, 5, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    bool result = optimal(arr , n ,target);
    cout << result << endl;

    // Call the function
    auto ans = optimal2(arr, n, target);

    // Print the result
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}