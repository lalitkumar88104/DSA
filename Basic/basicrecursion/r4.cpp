#include<bits/stdc++.h>
using namespace std;

void reverse(array<int,5> &a , int i , int n){
    if (i>=n){
        cout << "aray after reversing : ";
        for(const auto &x : a){
            cout << x << " ";
        } return ;
    }
    swap(a[i],a[n]);
    reverse(a ,i+1 ,n-1) ;
}

void palin(string s ,string orignal , int i , int n){
    if (i>=n){
        if(s == orignal){cout << s << " is palindrome" ;}
        else cout << s << " is not a plaindrome" << endl ;
        return ;
    }
    swap(s[i],s[n]);
    palin(s, orignal , i+1 ,n-1);
}

void pal(string s , int i ,int n){
    if (i>=n){
        cout << s << " is palindrome" << endl;
        return;
    }
   else if (s[i] == s[n]) {
        i = i+1;
        n =  n-1;
        pal(s , i ,  n);
    }
    else {cout << s << " is not a palindrome" << endl;
    return;} 
}

bool palindrome(string s ,int i ){
    if (i >= s.size()/2) return true;
    else if (s[i] != s[s.size()-i-1]) return false;
    return palindrome(s,i+1);
}

int main (){
array <int,5>arr = {10,20,30,40,50};
cout << "array before reversing : ";
for(const auto &x : arr){
    cout << x << " " ;
}cout << endl;
reverse(arr,0,arr.size()-1);

string s;
cin >>  s ;
palin(s , s, 0 , s.size()-1);

pal(s,0,s.size()-1);

cout << palindrome(s,0);
    return 0;
} 