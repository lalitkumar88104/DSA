#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter word : ";
    cin >> s;
    map<char,int> freq;
    for(int i  = 0 ; i< s.size(); i++){
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