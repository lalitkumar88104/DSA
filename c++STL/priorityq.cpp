#include<bits/stdc++.h>
using namespace std;
int main(){
priority_queue<int> pq;     // MAX heap

// Insertion
pq.push(99);
pq.emplace(103);
pq.emplace(5);
pq.emplace(8);
pq.emplace(44);

// Deletion

pq.pop();

// Acessing

cout<<"MAX heap order: "<< endl <<pq.top();

//   Utility
cout << endl << pq.size() <<endl << pq.empty() << endl;


// MIN heap

priority_queue<int , vector<int> , greater<int>> mpq ;
mpq.push (9);
mpq.emplace(89);
mpq.emplace(87);
mpq.emplace(103);

cout << "MIn heap order : " <<mpq.top();

    return 0 ;
}