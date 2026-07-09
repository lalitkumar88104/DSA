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


int main(){
int n;
cout << "Declare size of array : ";
cin >> n ;
int arr[n];
for(int i = 0 ; i<n ; i++){cin >> arr[i];}
selection_sort(arr,n);
for(int i=0 ; i <n ; i++){
    cout << arr[i] << " ";
}cout << endl;
for( auto it : arr){
    cout << it << " ";
}
    return 0;
}