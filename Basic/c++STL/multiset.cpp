#include<bits/stdc++.h>
using namespace std;
int main(){
multiset<int> ms ={44,55,55,55,66};

// insertiom

ms.insert(22);
ms.emplace(22);
ms.emplace(99);


// Deletion 
multiset<int>::iterator it = ms.begin();
advance(it,1);

for(const auto  &x :ms ){
    cout << x << " " ;
}cout << endl;

it = ms.erase(it);                   // eraser with itreator 
for(const auto  &x :ms ){
    cout << x << " " ;
}cout << endl;

ms.erase(22);                  // Erase by value 
for(const auto  &x :ms ){
    cout << x << " " ;
}cout << endl;

ms.erase(ms.find(66));         // Erase with find fun
for(const auto  &x :ms ){
    cout << x << " " ;
}cout << endl;

auto y = ms.begin();
advance (y,3);
ms.erase(it,y);                 // Erase with range , in this it wil erase 44 to because after assgin it we delete multiple values and it is still pointing at 44.
for(const auto  &x :ms ){
    cout << x << " " ;
}cout << endl;

//  Rest all fun are same find , count, size, empty, clear, rbegin,end etc

    return 0;
}