#include<bits/stdc++.h>
using namespace std;

void name(int i ,int n){                // print n times name
    if (i>n) return;
    cout << "lalit" << " ";
    name(i+1,n);
}

void linear(int n){                     // print 1 to n by backtracking
    if (n==0) return;
    linear(n -1);
    cout << n << " ";
}

void backward(int n){                   // print n to 1 without backtracking
    if (n == 0) return;
    cout << n << " ";
    backward(n-1);
}

void backbacktracking(int i ,int n){   // print n to 1 with backtracking
    if (i>n) return ;
    backbacktracking(i+1,n);
    cout << i << " " ;
}


int main  (){
int n;
cout << "enter the no : ";
cin >> n;
// name (1,n);
// backward(n);
backbacktracking(1,n);
    return 0;
}