#include <bits/stdc++.h>
using namespace std;

bool armstrong(int n){
    int v = n;
    int dup =n;
    int cnt = 0;
    int a = 0;
    while(v>0){
    v/=10;
    cnt++;
    }
    while (n>0){
        a = a+ pow(n%10,  cnt);
        n/=10;
    }
    if (dup == a)return true;
    return false;
}

int main(){
int t;
cout<< "Enter test cases : ";
cin >> t;

for(int i =0 ; i<t ; i++){
    int n ;
    cin >> n;
    bool a =armstrong(n);
    cout << a << endl;
}

    return 0;
}