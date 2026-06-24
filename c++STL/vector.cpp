#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>v;
// How to add element in vector
v.push_back(10);
cout << v[0] << endl ;
v.emplace_back(20);
cout << v.at(1) << endl;
v.emplace_back(30);
cout << v[2] << endl ;

// iterators 
// v.begin();
vector<int>:: iterator hy = v.begin();
cout << "value at begning : " << *hy << endl ;

// v.rbegin();
vector<int> :: reverse_iterator yo = v.rbegin();
cout <<"value at reverse begin function : "<< *yo << endl ;
yo = ++yo;
cout<< "value of r.begin after ++ : "<< *yo << endl;
// v.end();
auto it =v.end();
cout << "value at end : "<< *it << endl;
it--;
cout << "value at end -- : " << *it << endl;
// v.rend();
auto rit = v.rend();
rit--;
cout<< "value at rend -- : " << *rit << endl;
// v.back();
cout << "hey i am v.back I return last value of vector : " << v.back() << endl;
    return 0;
}