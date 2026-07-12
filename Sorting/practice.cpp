#include<bits/stdc++.h>
using namespace std;
void sort(int arr [] ,int n){
for (int i = 0 ; i<n-1 ; i++){
    for(int j = i+1 ; j>0 ; j--){
        if(arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1]= temp;
        }
    }
}
}

void merge(int arr[],int low , int mid ,int high){
    vector <int> temp;
    int left = low;
    int right = mid+1 ;

    while(left<=mid && right <=high){
        if(arr[left] <= arr [right]){
            temp.emplace_back(arr[left]);
            left++;
        }
        else{
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    while(left<= mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.emplace_back(arr[right]);
        right++;
    }
    for(int i = low ; i<=high ; i++){
        arr[i] = temp[i-low];
    }
}

void mergesort(int arr[] , int low , int high){
    if(low >= high) return;
    int mid = (low + high)/2;
    mergesort(arr , low ,mid);
    mergesort(arr , mid+1 , high);
    merge(arr ,low , mid, high);
}

int indx (int arr [] , int low , int high){
    int pivot = low;
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= arr[pivot] && i < high){
            i++;
        }
         while(arr[j] > arr[pivot] && j  >low){
            j--;
        }
        if (i<j){
            int temp = arr[i];
            arr[i] = arr [j];
            arr[j] = temp;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    return j;
}
void quicksort(int arr[] , int low , int high){
    if(low < high){
    int pindx = indx(arr , low , high);
    quicksort(arr , low ,pindx-1);
    quicksort(arr , pindx +1 , high);}
}

void selection(int arr[],int n){
for(int i = 0 ; i < n ;i++){
    int min = i;
    for (int k =i+1 ; k< n ;k ++){
        if(arr[min] > arr[k]) min = k;
    }
    int temp = arr[min];
    arr[min] =arr [i];
    arr[i] = temp;
}
}

void bubble(int arr[], int n){
for (int i=0 ; i < n-1 ; i++){
    bool swap = false;
    for(int k = 0 ; k < n-i-1 ;k++){
        if(arr[k] > arr[k+1]){
            int temp = arr[k];
            arr[k] = arr[k+1];
            arr[k+1] = temp;
            swap = true;
        }
    }
    if(!swap) return;
    cout<<"run" <<" ";
}
}

void insertion(int arr[] ,int n){
for(int i =1 ; i<n ; i++){
    for(int k= i ; k >=1 && arr[k] < arr[k-1] ;k--){
        
            int temp = arr[k];
            arr[k] = arr[k-1];
            arr[k-1] =temp;
        
    }
}
}

void insertionshift(int arr[] , int n){
    for (int i= 1 ; i< n ;i++){
        int j= i;
        int temp = arr[i];
        while(j>=1 && temp < arr[j-1]){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}
int main(){
int n;
cout << "Declare size of array : ";
cin >> n ;
int arr[n];
for(int i = 0 ; i<n ; i++){cin >> arr[i];}
insertionshift(arr,n);
for (int i = 0 ; i<n ; i++){
    cout << arr[i] << " ";
}
// for( auto it : arr){
//     cout << it << " ";
// }
    return 0;
}