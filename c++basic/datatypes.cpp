// instead of using all libraries we can use 1 library that contains all the library
#include<bits/stdc++.h>
using namespace std;
// for dsa we need some data types if we need  other we can search it on google
int  main(){
    // int, long, long long, double, float 
    // int = +-10^9 , long = +-10^12 , long long = +-10^18
    // string and getline
    // char
    long x;
    cin >> x;
    cout << " value is : " << x << endl ;

    string word;  //string is used for store word before space after space it will ignore all 
    cin >> word ;
    cout << " word is : " << word << "\n";

    string str; // for storing the line we will use getline fun before cin and in place of >> we use ,
    getline(cin , str);
    cout << "string is : " << str << endl;

    char c;
    cin >> c;
    cout << " chracter is : " << c <<  "\n";

    return 0 ;
}