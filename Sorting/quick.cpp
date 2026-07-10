#include<bits/stdc++.h>
using namespace std;

int fun(int arr[] ,int low ,int high){
int pivot = low;
int i= low ;
int j = high;
while(i<j){
    while(arr[i] <= arr[pivot] && i < high){
        i++;
    }
    while(arr[j] > arr[pivot] && j > low){
        j--;
    }
    if(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int  temp = arr[pivot];
arr[pivot] = arr[j];
arr[j] = temp;
return j;
}

void quicksort(int arr[], int low , int high){
    // if(low == high || low > high) return;
    if(low<high){
    int partition_indx = fun(arr , low ,high);
    quicksort(arr , low , partition_indx -1);
    quicksort(arr , partition_indx +1 , high);
}}



int main(){
    int n;
cout << "Declare size of array : ";
cin >> n ;
int arr[n];
for(int i = 0 ; i<n ; i++){cin >> arr[i];}
quicksort(arr , 0 , n-1);
for(int i=0 ; i <n ; i++){
    cout << arr[i] << " ";
}cout << endl;
for( auto it : arr){
    cout << it << " ";
}
    return 0;
}