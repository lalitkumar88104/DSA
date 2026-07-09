#include<bits/stdc++.h>
using namespace std;
void sort(int arr [] ,int n){
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