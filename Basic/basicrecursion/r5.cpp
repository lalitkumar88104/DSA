#include<bits/stdc++.h>
using namespace std;

int fibnaci(int n){
    if (n<=1) return n;

    return fibnaci(n-1)+ fibnaci(n-2);
}

int main(){
int t ;
cout << "Enter no of test cases : ";
cin >> t;
for (int i=0 ; i<t ; i++){
    int n ;
    cin >> n;
    cout << fibnaci(n) << endl;
}
}