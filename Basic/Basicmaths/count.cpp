#include<bits/stdc++.h>
using namespace std;

int count (int n){
    int a = 0;
    do {
        n/=10 ;
        a++;
    }while (n > 0);
    return a ;
}

int main (){

int t;
cin >> t;
for(int i = 0 ; i< t ; i++){
    int n ;
    cin >> n;
   int a = count(n);
    cout << a << endl;
}
// cout << typeid(pow(153%10 , 2) ).name();
    return 0;
}