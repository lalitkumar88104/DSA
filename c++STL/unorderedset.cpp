#include<bits/stdc++.h>
using namespace std;
int main(){
unordered_set<int> us = {10,5,20,15,50,45,30,30};

    // insertion

    us.insert(100);
    us.emplace(12);
    us.emplace(12);   // Insertion at particular positionis not allowed in any set it will compile but it will ignore 

    for(const auto &x : us ){
        cout << x << " ";
    }cout << endl ;


    // Deletion

    unordered_set<int> :: iterator it = us.begin();
    advance(it,2);
    it = us.erase(it);              // Delete with itreator

    
    for(const auto &x : us ){
        cout << x << " ";
    }cout << endl ;
    

    us.erase(10);                  // Delete with element
    
    for(const auto &x : us ){
        cout << x << " ";
    }cout << endl ;

    auto x = us.begin();
    advance(x,4);
    us.erase(it,x);             // Deleet a range of element 
    
    for(const auto &x : us ){
        cout << x << " ";
    }cout << endl ;


    // acess 

    
    unordered_set<int>::iterator y = us.begin();
    advance(y,2);
    cout << *y<< endl;

    auto v = us.find(13);
    cout << *v << endl;         // this is wrong way to do as if element is not present in set it will assgin v == us.end()
                                // which is undefined behaviour so always use if else statment if v == us.end() print not found
    cout << "exit";             // see after this code is not working 

    // rest all fun are same as count, .rbegin , .rend, swap , clear etc
    return 0;
}