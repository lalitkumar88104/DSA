#include<bits/stdc++.h>
using namespace std;

int algo(int n1 , int n2){
    while (n1>0 && n2 > 0){
        if (n1>n2) n1 = (n1%n2);
        else  n2 = (n2%n1);
    }if (n1 == 0) return n2;
    return n1;
}

int main(){
int t;
cout<< "Enter test cases : ";
cin >> t;

for(int i =0 ; i<t ; i++){
    int n , n2;
    cin >> n >> n2;
    int a = algo(n , n2);
    cout << a << endl;
}

    return 0;
}