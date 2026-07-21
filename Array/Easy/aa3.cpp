# include <bits/stdc++.h>
using namespace std;

int maxconsecutive(int arr[] , int n){  // no brute better required; optimal sol for maximum consecutives 1s in an array; tc = O(n); sc = O(1) 
    int count = 0;
    int maximum = 0;
    for(int i =0 ; i<n ; i++){
        if(arr[i]== 1){
            count++;
            if (maximum <= count){
                maximum = count;
            }
        }
        else count = 0;
    }
    return maximum;
}

// Find the no that appears once and another twice;

// brute sol
int brute(int arr[] , int n){   // sol use classic nested linear search; tc = O(n*n); sc = O(1);
    for(int i = 0 ; i < n ; i++){
        int count = 0;
        for(int j = 0 ; j< n ; j++){
            if(arr[i] == arr [j]){
                count++;
            }
        }
        if (count == 1) return arr[i];
    }
    return -1;
}

// better sol using hashing 

// by array hashing
int better(int arr[] , int n){  // tc = O(3n) ; sc = O(maxi);
    int maxi = 0;
    for(int i= 0 ; i<n ; i++){
        maxi = max(arr[i] , maxi);
    }
    int hash[maxi +1] = {0};
    for(int i = 0 ; i < n; i++){
        hash[arr[i]]++;
    }
    for(int i = 0 ; i<n ; i++){
        if(hash[arr[i]] == 1) return arr[i];
    }
    return -1;
}

// by using map;
int bettermaphashing(int arr[] , int n ){   // tc = O(n) for besst case , O(n*n) for worst case; n as we are running loop for insertion and fetching data for n times so best case of um is O(1) *O(n) = O(n);
    unordered_map <long long , int> hash;   // tc & sc for map is; tc =o(nlogm) n = size of array and m = size of map;
    for(int i =0 ; i<n ; i++){
        hash[arr[i]]+=1;
    }
    for(const auto it : hash){
        if(it.second == 1) return it.first;
    }
    // for(int i = 0 ; i<n ; i++){
    //     if(hash[arr[i]] == 1)
    //     return arr[i];
    // }
    return -1;
}

// why map is better for values larger than 10^5 and for negative values;

int optimal(int arr[] , int n){  // tc = O(n) ; sc = O(1);
    int xor1 = 0;
    for(int i =0 ; i <n ; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n]; // declare array of size n

    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = bettermaphashing(arr, n);
    cout << "Result : " << result << endl;

    return 0;
}