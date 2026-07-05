#include<bits/stdc++.h>
using namespace std;

void summ(int n ,int s)          //sum of n no with parametrized fun
{
if (n==0) 
{cout<< s ;
return;}
summ(n-1 ,s+n);  
}

int sum(int n){                 //sum of n no with function or non parmetarized fun
    if (n==0) return 0 ;
    return n + sum(n-1);
}

int factorial(int n){          // factorial with non parametrized fun
    if (n==0) return 1;
    return n * factorial(n-1);
}

void fac(int i ,int n){
    if (i == 0){
        cout << n;
        return ;
    }
    fac(i-1,n*i);
}

int main(){
int n ;
cout << "Enter the no : ";
cin >> n ; 
// summ(n ,0);
// cout << factorial(n);
fac(n,1);
return 0;
}