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
bool palindrome (string &s , int i){
    if (i >= (s.size())/2) return true ;
    if(s[i]!= (s[s.size()-1-i])) return false;
    return palindrome(s , i+1);
}
int main(){
int t ;
cout << "Enter no of test cases : ";
cin >> t;
for (int i=0 ; i<t ; i++){
    string n ;
    cin >> n;
    cout << palindrome(n ,0 ) << endl;
}
}