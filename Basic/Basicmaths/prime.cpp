#include<bits/stdc++.h>
using namespace std;
bool prime (int n){
int  i = 1;
while (n>= i*i){
if (n%i == 0){
    if (i !=1)return false;
}
i++;}return true;
}

bool primen(int n){
    if (n<=1) return false;
    int i = 2;
    while (i*i <= n){
        if (n%i == 0) return false;
        i++;
    } return true;
}

int main(){
int t; 
cout << "Enter testt cases : ";
cin >> t;  
for (int i = 0 ; i <t ; i++){
    int n;
    cin >> n;
    // cout << prime(n) << endl;
    cout << primen(n) << endl;
}

    return 0;
}