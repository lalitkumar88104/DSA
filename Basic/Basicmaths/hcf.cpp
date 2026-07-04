#include<bits/stdc++.h>
using namespace std;

int GCD(int n1 ,int n2){
    int GCD = 1;
    for (int i=1 ; i <=(min (n1 ,n2)) ; i++){
        if (n1%i == 0 && n2%i == 0)
        GCD = i;
    } 
    return GCD;
}

int gcd(int n1 , int n2)
{
    int i = min(n1,n2);
    while ( i >0){
        if (n1%i == 0 && n2%i == 0) return  i;
        i--;
    }
}
int main(){
int t;
cout<< "Enter test cases : ";
cin >> t;

for(int i =0 ; i<t ; i++){
    int n , n2;
    cin >> n >> n2;
    int a = gcd(n , n2);
    cout << a << endl;
}
    return 0;
}