#include<bits/stdc++.h>
using namespace std;

// properties of pascal triangle : n th row of pascal triangle has n no of elemrnts or col;

// Pascal triangle 1 = print element at nth row and cth col;
int nCr (int row , int col){                // tc = O(col); sc = O(1);
    row = row-1 , col = col-1;
    if (col > row -col) col = row - col;   // Choose the smaller value for lesser iterations
    int result = 1;
    for(int i = 0 ; i<col ; i++){
        result = result *(row - i);
        result = result / (i+1);
    }
    return result;
}

// Pascal's triangle 2 = print the full row;  tc = O(n) ; sc = o(1)

void pascal (int n){        // n = no of row; n th row of pascal triangle has n no of elemrnts or col;
    long long ans = 1;
    cout << ans << " ";
    for(int i = 1 ; i< n; i++){
        ans = ans * (n-i);
        ans = ans/i;
        cout << ans << " ";
    }
}


// Pascal's triangle 3 = print pascal's triangle till nth row;



int main(){
int n = 5;
pascal(6);
// int result = nCr(6,1);
// cout << result;
    return 0;
}