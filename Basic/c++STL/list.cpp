#include<bits/stdc++.h>
using namespace std;

int main(){
list<int> ls ={1,2,3,4,5,6,7,8,9};

// insertion
ls.push_back(10);
ls.emplace_back(11);
ls.push_front(0);
ls.emplace_front(01);
ls.insert(ls.end(),12);
auto x=next(ls.begin(),2);          // to insert or erase at pos use next , prev , advamced
ls.insert(x,999);
ls.insert(ls.begin(),{11 , 12}); 

for(const auto &x:ls){
    cout << x << " ";
}cout << endl ;


// Deletion 
cout<< "I print for deletion" << endl ;
auto y  = (ls.end());
advance(y,-2);              // Using advance
ls.erase(y);                // advance dosent return any value it just moves

for(const auto &x:ls){
    cout << x << " ";
}cout << endl ;

ls.pop_back();
ls.pop_front();

for(const auto &x:ls){
    cout << x << " ";
}cout << endl ;

// acess

cout << "I am printing for Acess"<< endl << ls.front() << endl;
cout<< ls.back()<< endl;


auto pos = ls.begin();
advance(pos , 3);           // Acessing using iterator 
cout << *pos << endl ;
// advance(pos,13);
// cout << *ls.rend() << " garbage value" << *pos ;

//  special fun 
ls.reverse();
for ( const auto &y :ls ){
    cout << y << " ";
}    cout << endl;

ls.sort();
for( const auto &y : ls ){
    cout<< y << " ";
}cout << endl << "I will print for merge : " << endl;

list <int > l ={99,98,97,96};
ls.merge(l);
for (const &y : ls){
    cout << y << " ";
}cout << endl << "I will; print for unique : "<< endl;

ls.unique();
for(const &y : ls){
    cout << y <<  " ";
}cout << endl ;
    return 0;
}