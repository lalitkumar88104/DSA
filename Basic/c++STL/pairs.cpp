#include<bits/stdc++.h>
using namespace std;

int main(){
pair<int , char> p = {1, 'g' } ;
cout << p.first << " "<<  p.second << endl;

// Nested Pair

pair<int, pair <char , int>> nested = {1,{'A',3}};
cout << nested.first << " " << nested.second.second << endl ;

// array of pairs

pair<int,int> arr[3]= { {1,2} , {2,3}, {4,5}};
cout << arr[1].first << endl;

// input in pairs

pair<int , int> input ;
cin >> input.first >> input.second ;
cout << input.second<< " " << input.first << endl ;
    return 0;
}