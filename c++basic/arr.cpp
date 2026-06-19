#include<bits/stdc++.h>
using namespace std;

int main(){
// 1D array
int arr[5];
cin >> arr[4]; // 5 element of array will store in 4th index 5th is not existing
cout << arr[4] << endl;


// 2d aray
int arra[5][5];
arra[0][4] = 867 ;
cout << arra[0][4] << endl ;

// we  use string keyword for storing string as an array that are made up of  chracter

string s;
s = "hey Lalit " ;
cout << s << endl ;
int len;
len = s.size() ;
cout << len << endl << s[len-2] << endl ;
string g;
cin >> g; // with cin function it takes upto space only
cout << g;
    return 0;
}
