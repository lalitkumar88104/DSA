#include<bits/stdc++.h>
using namespace std;
int main(){
deque <int> dq =  {4,5,6};

// Insertion
dq.push_front(3);
dq.emplace_front(2);
dq.push_back(7);
dq.emplace_back(8);
auto x =  dq.begin();
advance(x,0);
dq.insert(x,1);
x=dq.begin();
advance(x,8);
dq.insert(x,{9,10,11});

for(const auto x:dq){
    cout <<x<< " ";
}
cout << endl ;


// Deletion
cout << "I will print for deletion : ";
dq.pop_back();
dq.pop_front();
x=dq.begin();
advance(x,4);
dq.erase(x);

for(   const auto x:dq ){
    cout << x << " ";
}cout << endl<< "I will print for acessing : " ;

// Acessing

cout << dq.front()<<endl << dq.back()<<endl << dq[2]<<endl << *x << endl; 


// special fun
// No special fun as list
    return  0;
}