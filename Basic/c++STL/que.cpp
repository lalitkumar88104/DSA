#include<bits/stdc++.h>
using namespace std;
int main (){
queue<int>q ;
// Insertion
q.push(9);
q.emplace(6);
q.emplace(5);
q.emplace(4);

// deletion 

q.pop();

// Acess

cout << q.front()<< endl << q.back()<< endl;

// utility
cout << q.size()<<endl << bool(q.empty());
    return 0;
}