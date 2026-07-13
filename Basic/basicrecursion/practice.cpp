#include<bits/stdc++.h>
using namespace std;

int summ(int n ,int total){
if(n == 0) return total;
return summ  (n-1 , total + n);
}
int sum(int n){
if(n<1) return 1;
return n * sum(n-1);
}

int main(){
int t ;
cout << "Enter no of test cases : ";
cin >> t;
for (int i=0 ; i<t ; i++){
    int n ;
    cin >> n;
    cout << sum(n ) << endl;
}
}