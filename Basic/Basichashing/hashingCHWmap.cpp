#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter word : ";
    cin >> s;
    map<char,int> freq;                     // Its always a better option to use unordered map becuae unordered map has less time commplexity
    for(int i  = 0 ; i< s.size(); i++){     // use map only when unorderd map says time limit exceeded there is nod difference btw map and unoredered map
        freq[s[i]]++;
    }
    int query;
    cout << "Enter no of query : ";
    cin >> query;
    while(query --){
        char c;
        cout << "Enter chracter : ";
        cin >> c;
        cout << freq[c] << endl;
    } 
}