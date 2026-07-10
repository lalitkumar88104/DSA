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

int main(){
int n;
cout << "Declare size of array : ";
cin >> n ;
int arr[n];
for(int i = 0 ; i<n ; i++){cin >> arr[i];}
sort(arr,n);
for(int i=0 ; i <n ; i++){
    cout << arr[i] << " ";
}cout << endl;
for( auto it : arr){
    cout << it << " ";
}
    return 0;
}