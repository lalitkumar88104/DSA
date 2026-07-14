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
    cout << sorted(arr , n);
    return 0;
}