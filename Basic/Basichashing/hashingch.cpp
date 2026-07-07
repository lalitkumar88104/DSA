#include<bits/stdtr1c++.h>
using namespace std;

int main(){
    string s;
    cout << "enter the word : ";
    cin >> s;

    int hash[26] = {0};               // for whole chracter present in world we can simply set the value of arrray to 256
    for(int i=0 ; i<s.size(); i++){   // as after using 256 there is no need to  - ch from a 
        hash[s[i]-'a'] ++;
    }

    int query;
    cout << "enter no of query : ";
    cin >> query ;
    while(query --){
        char c;
        cout << "Enter chracter : ";
        cin >> c ;
        cout << hash[c-'a'] << endl ; 
    }
    return 0;
}