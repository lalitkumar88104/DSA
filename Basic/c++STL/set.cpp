#include<bits/stdc++.h>
using namespace std;
int main(){
set <int> s  = {4,5,6};

// Insertion

s.insert(9);
s.insert(97); // insertion at particular position wil not work here 
s.emplace(67); // push fun didnt work here too 
s.emplace(34);
s.emplace(12);
s.emplace(87);
s.emplace(67);

// Deletion

s.erase(12);
auto x = s.begin();
advance(x,2);
x = s.erase(x); // because of x= it will erase value at x and points towards next value 
cout << *x << endl;

auto y = s.begin();
advance (y,4);
s.erase (x,y );
advance (y,3); // you can use same iterator as many time you want 

// Acess/search

set<int>::iterator it = s.find(97);
cout << *it << endl ;
cout  << s.count(100)<< endl;


// special fun for set : Lower bound and Upper bound

for (const auto &x : s){
    cout << x << " ";
}cout << endl;



// Lower bound
auto itt = s.lower_bound(5);   // give iterator of value if present or next value if not
cout << *itt << endl ;

// Upper bound
auto ind = s.upper_bound(87);  // gives always 1 greater value ehat u search either is present in set or not 
cout << *ind << endl;

    return 0;
}