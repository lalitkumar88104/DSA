#include<bits/stdc++.h>
using namespace std;
bool palindrome(int n){
    int temp = n;
    int a=0;
    while(temp>0){     // if u want to calculate -ve value to use temp only
        a = (a*10) + (temp%10);
        temp /= 10;
    }
    if (a == n) return true;
    return false;
}


int main(){
int t;
cout << "enter no of test cases : ";
cin >> t;
for (int i =0 ; i<t ; i++){
    int n;
    cout << "Enter the value : ";
    cin >> n ;
   bool a = palindrome(n);
   cout << a << endl;
}
    return 0;
}