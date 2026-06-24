#include <bits/stdc++.h>
using namespace std;


void arr(int a[] , int n){
    for(int i = 0 ; i <n ; i++){
        a[i]= a[i] +10 ;
        cout << a[i] << "this is inside function" <<endl ;
    }
}
int main() {
    // int x;
    // cin >> x;
    // cout << "hey " << x << endl;

    int n;
    cout << "enter value of array index : " << endl ;
    cin >> n;
    int arrr[n];
    for (int a = 0 ; a <n ; a++){
        cin >> arrr[a];
    }
    arr(arrr, n);
        cout << "value of array inside main : " << arrr[0] << endl  ;
    return 0;
}