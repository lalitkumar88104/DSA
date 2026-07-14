#include<bits/stdc++.h>
using namespace std;

int Slargest(int arr[] , int n){        // better sol for second largest element in a array; tc = O(2n)
    int largest = arr[0];
    int slargest = INT_MIN;
    for(int i = 1 ; i<n; i++ ){
        if(largest< arr[i]){
            largest = arr[i];
        }
    }
    for(int i =0 ; i<n ; i++){
        if(slargest <arr[i] && arr[i] < largest)
        slargest = arr[i];
    }
    return slargest;
}

int ssmallest(int arr[] ,int n){        // better sol for second smallest element in array; tc = O(2n)
    int smallest = arr[0];
    int Ssmallest = INT_MAX;
    for(int i = 1 ; i<n ; i++){
        if (arr[i]< smallest) smallest = arr[i];
    }
    for(int i = 0 ; i<n ;i ++){
        if(arr[i] < Ssmallest && arr[i] > smallest) Ssmallest = arr[i];
    }

    return Ssmallest;
}

int secondlargest(int arr[] , int n){   // optimal sol for second largest element; tc = O(n)
    int largest = arr[0];
    int slargest = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]> largest){
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > slargest && arr[i]<largest) slargest = arr[i];
    }
    return slargest;
}

bool sorted (int arr[] , int n){
    for(int i=0 ; i<n-1 ; i++){
        if(arr[i+1]< arr[i]){
            return false;
        }
    }
    return true;
}

int indx(int arr[] ,int n){            // bruteforce sol for removing duplicate values; tc = O(n log n + n); sc = O(n)
    set <int> st;
    for (int i =0 ; i<n ; i++){
        st.insert(arr[i]);
    }
    int index = 0;
    for (auto it : st){
        arr[index] =it;
        index++;
    }
    return index;
}

int unique(int arr[] , int n ){     // optimise sol for removing duplicate; tc = O(n); sc = O(1)
    int i = 0 ;
    int j = 0;
    while(j<n){
    while(arr[i]==arr[j]){
        j++;
    }
    if (arr[i]!= arr[j] && j<n){
        arr[i+1] = arr[j];
        i++;
        j++;
    }
    } return i+1;
}

int uniquee(int arr[] , int n ){    // optimise sol for removing duplicate with refine code; tc = O(n); sc = O(1)
    int i = 0 ;
    int j = 0;
    if (n==0) return 0;
    while(j<n){
    if (arr[i]!= arr[j]){
        arr[i+1] = arr[j];
        i++;
    }
    j++;
    } return i+1;
}

int removeDuplicates(int nums[], int n) {
        if(n == 0) return 0;
        int i = 0;
        for(int j = 1 ; j < n ;j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }

int main(){
    int n ;
    cout << "enter the size of array : ";
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    // int slargest = Slargest(arr , n);
    // if (slargest == INT_MIN) cout << "no second largest avaliable" ;
    // else cout << slargest <<" I am second largest in array "<< endl;
    // cout << sorted(arr , n);
    int index = removeDuplicates( arr ,n);
    for (int i = 0 ; i < index; i++){
        cout << arr[i] << " ";
    } cout << endl;
    for (int i = 0 ; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}