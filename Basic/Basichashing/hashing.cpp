#include<bits/stdc++.h>
using namespace std;

int main(){

    //  Array declaration

    int size ; 
    cout << "Declare the ssize of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter the element of array : " << endl;
    for (int i = 0 ; i<size ; i++){
        cin  >> arr[i];
    }

    // Pre computation
    int hash[13] = {0};
    for(int i= 0 ;i<size ; i++){
        hash[arr[i]] += 1;
    }
    // Fetching 
    int query;
    cout << "enter no of element you want to search : ";
    cin >> query ;
    while(query--){
        int num;
        cout << "Enter no : ";
        cin >>num ;  
        cout << hash[num] << endl;
    }
    return 0 ;
}