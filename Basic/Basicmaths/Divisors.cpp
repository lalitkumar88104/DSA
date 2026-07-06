#include<bits/stdc++.h>
using namespace std;

void divisor (int n){
    for(int i=1 ; i*i <= n ; i++ ){
        if (n % i == 0){
            cout << i << " " << n/i << " ";
        }
    }
}

vector<int> div (int n){
    int i = 1;
    vector<int> v;
    while (i*i <= n){
        if (n%i == 0){
            v.emplace_back(i);
            if (i != n/i) v.emplace_back(n/i);
        } i++;
    }
    sort(v.begin(),v.end());
    return v;
}

int main(){
int t; 
cout << "Enter testt cases : ";
cin >> t;  
for (int i = 0 ; i <t ; i++){
    int n;
    cin >> n;
    // divisor(n);
    vector <int> v = div(n);
    bool comma = true;
    for(const auto &x : v){
        if (!comma)
        cout <<",";
        cout << x ;
        comma = false ;
    }
}

    return 0;
}