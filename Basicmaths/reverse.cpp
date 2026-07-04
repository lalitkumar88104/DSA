#include<bits/stdc++.h>
using namespace std;

int rev(int n){
    int a = 0 ;
    while (n>0){
        a = (a*10) + (n%10)  ;
        n/=10;
    }
    return a;
}

int main(){
int t;
cout<< "Enter test cases : ";
cin >> t;

for(int i =0 ; i<t ; i++){
    int n ;
    cin >> n;
    int a =rev(n);
    cout << a << endl;
}
    return 0;
}