#include<bits/stdc++.h>
using namespace std;
int main (){
stack<int> st;

// insertion

st.push(1);
st.emplace(2);
st.emplace(3);

// Deletion
st.pop();

// Acess

int s = st.top();
cout << s << endl ;     
// we cant acess full stack at once
//  and also cant use all fun that is applicable on list and deque 

// utility fun
cout << st.size()<< endl << st.empty() << endl ;
stack <int> stt;
stt.emplace(99);
stt.emplace(88);
st.swap(stt);
cout <<st.top();
    return 0;
}