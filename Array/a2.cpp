#include<bits/stdc++.h>
using namespace std;

void left (int arr[] , int n){         // optimal sol for rotate array left by one no brute better required ;
    int temp = arr[0];
    for(int i = 1 ; i<n ; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

void bruteleftd(int arr[] , int n , int d){     // brute sol for left array rotation by d 
    d = d % n;
    int temp[d];
    for(int i = 0 ; i<d ; i++){         // store
        temp[i] = arr[i];
    }
    for(int i = d ; i<n ; i++){         // shift
        arr[i-d] = arr[i];
    }
    for(int i = n- d ; i<n ; i++){      // copy
        arr[i] = temp[i-(n-d)];
    }
}

void optimalleft(int arr[] , int n , int d){       // optimal sol for left array rotation by d
    d = d%n;
    reverse(arr , arr +d);       // in array name of array work as iterator;
    reverse(arr + d , arr +n );
    reverse(arr , arr+n);
}

void end (int arr[] ,int n ){           // brute force sol for move all non zero no to end;
    vector <int> temp;
    // step 1 - store non zero no;
    for(int i = 0 ; i < n ; i++){
        if (arr[i] != 0) temp.emplace_back(arr[i]);
    }
    // step 2 - put all non zero no at starting of the array;
    for (int i = 0 ; i < temp.size() ; i++){
        arr[i] = temp[i];
    }
    // step 3 - place 0 at remaning place
    for(int i = temp.size(); i<n ; i++){
        arr[i] = 0;
    }
}

void optimalend(int arr[] , int n){
    int j = -1;

    for(int i = 0 ; i<n ; i++){
        if (arr[i] == 0){
        j = i ;
        break;}
    }
    if (j == -1) return;

    for(int i = j+1 ; i<n ;i++){
        if(arr[i] != 0){
            swap(arr[i] , arr[j]);
            j++;
        }
    }
}


int main(){
    int n ;
    cout << "enter the size of array : ";
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    // int d;
    // cout << "enter no of rptation you want : ";
    // cin >> d;
    // optimalleft( arr ,n , d);
    optimalend(arr , n);
    for (int i = 0 ; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}