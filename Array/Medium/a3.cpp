#include<bits/stdc++.h>
using namespace std;

// Majiority element : element that appears more than (n/2)half;

// brute
int brute(int arr[] , int n){              // tc = O(n*n); sc = O(1)
    for(int i =  0 ; i<n ; i++){
        int count = 0;
        for(int j = 0 ; j<n ; j++){
            if(arr[j] == arr[i]){
                count ++;
            }
        }
        if (count > n/2) return arr[i];
    }
    return -1;
}

// better
int better(int arr[] , int n){         // tc = O(nlogn); sc = O(n);
    map <int , int > maxi;
    for(int i = 0 ; i<n ; i++){
        maxi[arr[i]] += 1;
    }
    // int maximumkey = 0;
    // int maximum = 0;
    for( auto it : maxi){
        if(it.second > n/2) return it.first;
        // if( it.second > maximum){
        //     maximum = it.second;
        //     maximumkey = it.first;
        // }
    }
    // return maximumkey;
    return -1;
}


//optimal sol
// using moore's voting algo : moores voting algo states that pick first element and make count = 1 
// and compare it with nexet elements (if element is same count++; else count--) 
// until count == 0 then element will be arr[i] ,
// again repeat this process until array completes then check is that element in majiority or not 

int optimal(int arr[], int n){
    int count = 0;
    int element = 0;
    // for(int i = 0 ; i<n ; i++){      this for loop works exact same but id dosent follow mores voting algo ; algo states if count == 0 choose current element as candidate and then decrease increase this order prevnts out of bound condition or arr[i+1]
    //     // if (element == arr[i] ){
    //     //     count++;
    //     // }
    //     // else{
    //     //     count --;
    //     // }
    //     // if (count == 0){
    //     //     element = arr[i+1];
    //     // }
    // }
    
    for (int i = 0 ; i<n ; i++){
        if (count == 0){
            element = arr[i];
            ++count;
        }
        else if (element == arr[i]){
            count ++;
        }
        else {
            count --;
        }
    }
    int count1 = 0;
    for(int i = 0 ; i<n ; i++){
        if (element == arr[i]) {
            count1++;
        }
        if (count1 > n/2) return element;
    }
    return -1;

}

int main(){
    int arr[] = {7, 7, 5, 7 ,5, 1, 5, 7, 5, 5, 7 , 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = optimal(arr, n);

    if (ans == -1)
        cout << "No majority element found.";
    else
        cout << "Majority element: " << ans;
    return 0;
}