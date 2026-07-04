#include<bits/stdc++.h>
using namespace std;

// Functions are set of code which perform something for you
// functions are used to modularise code
// Funcctions are used to increase redabillity
// Functions are used to use same line of code multiple times 
// Void  -> which doess not return anything
// Return
// Paremetrized
// Non parrameterized


// WAP to take teo no and print their sum

void printname(string z) {
cout << "hey " << z <<  "!" << endl;
}

void sum(int a , int b){
    cout << "sum is : " << a + b << endl ;
}

// return way to  solve same q

int summ (int a, int b ){
    int sum =  a + b  ;
    return sum;
}

// passa by value -> in this orignal value will not change only copy of that value will be changed

string str(string a){
    a[0] = 'r';
    return a;
}

// pass by refrence -> in this orignal value will change and need to add & sign in parameter

string change(string &a){
    a[0] = 'r' ;
    return a;
}
int main(){
    string name;
    cin >> name;
    printname(name); 

    string y;
    cin >> y;
    printname(y);

    int c,d;
    cin >> c >>  d ;
    sum(c , d);

    int e,f ;
    cin >>  c >> d;
    int sum = summ(c ,d);
    cout << sum << endl ;

    string strr ;
    cout << "pass by value"<< endl ;
    cin >> strr;
    string res = str(strr);
    cout << res << endl << strr << endl;

    string data ;
    cout << "pass by reflrence" << endl ;
    cin >> data;
    string ress = change(data);
    cout << ress << endl << data;

    return 0;
}