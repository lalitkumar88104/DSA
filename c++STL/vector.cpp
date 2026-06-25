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

// how to print full length of vector {10,20,30}

for (auto st= v.begin(); st != v.end(); st++){
    cout  << *st << " " ;
}
cout << endl;
// how to print using for each loop 

cout << "I am printing using for each loop : ";
for (auto value : v){
    cout << value <<" ";
}

cout << endl;
//  how to modify using for each loop

for(auto &update : v){
    update += 10;
    cout << update << " ";
}
cout << endl ;
// read only using for each loop
for (const auto &x : v){
    cout << x << " ";
}
cout << endl;
// deletion of vector
v.erase(v.begin()+2);
for (auto st= v.begin(); st != v.end(); st++){
    cout  << *st << " " ;
}
cout << endl;
// deletion of seq of vector
v.emplace_back(40);
v.emplace_back(50);
v.emplace_back(60);
v.emplace_back(70);
v.emplace_back(80); // {20,30,40,50,60,70,80}

for(const auto &x : v  ){
cout<< x << " ";}
cout << endl ; 

v.erase(v.begin()+3,v.end()-1);
for(const auto &x : v  ){
cout<< x << " ";}
cout << endl ; 

// Insertion 

v.insert(v.begin()+3, 60);

//  insertion of multiple value inside vector

v.insert(v.end() -1,{90,100});
for(const auto &x:v){
    cout << x << " ";
}
cout << endl;

// how to insert vector inside another vector
vector <int> ch {1,2,3};

v.insert(v.begin()+1, ch.begin(),ch.end());
for (const auto &x : v){
    cout << x << " ";
}
cout << endl ;
// other function inside vector

v.pop_back(); // remove last element
for(const auto &x:v){
    cout << x << " ";
}
cout << endl;

int x = v.size(); // prints size of vector 
cout << x << endl ;
// cout << v. size () ;

swap(v , ch);               //
for(const auto &x:v){       //
    cout << x << " ";       //
}                           //
cout <<endl;                //
                            //  Swap 2 vectors
v.swap(ch);                 //
for(const auto &x:v){       //
    cout << x << " ";       //
}                           //

cout <<endl << v.empty() << endl;  
ch.clear();
cout << ch.empty()<< endl;
for (const auto &c : ch){
    cout << " value inside ch : "<< c ;
}
cout << endl;
    return 0;
}