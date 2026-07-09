#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i =0 ; i<= n-2 ; i++){
        int minn = i;
        for(int k = i; k < n; k++){
            // minn = min(minn , arr[k]); this is logically correct but we cant implement it as we cant swap num directly
            if(arr[minn] > arr[k]) minn = k;
        }
        int temp = arr[i];
        arr[i] = arr[minn];
        arr[minn] = temp;
    }
}

void bubble_sort(int arr[] ,int n){
for(int i = 0 ; i< n-1  ; i++){
    for(int k=0 ; k< n-i-1 ;k++){
        if(arr[k] > arr [k+1]){
            int temp = arr[k];
            arr[k] = arr[k+1];
            arr[k+1] =temp;
        }
    }
}
}

void bubble_sort2(int arr[], int n){
    for(int i= n-1 ; i >=1 ; i--){
        bool swap = false;
        for (int k =0 ; k < i ; k++){
            if(arr[k] > arr[k+1]){
            int temp = arr[k];
            arr[k] = arr[k+1];
            arr[k+1] = temp ;
            swap  = true ;
             }
        }
        if (!swap) break;
        cout << "run" << " "<< i << endl;
    }
}

int main(){
int n;
cout << "Declare size of array : ";
cin >> n ;
int arr[n];
for(int i = 0 ; i<n ; i++){cin >> arr[i];}
bubble_sort2(arr,n);
for(int i=0 ; i <n ; i++){
    cout << arr[i] << " ";
}cout << endl;
for( auto it : arr){
    cout << it << " ";
}
    return 0;
}