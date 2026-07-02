#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cout << "Enter the no you want to extaract : ";
cin >> n;
do {
   cout <<  n % 10 << "," ;
   n = n/10 ;
}while (n>0);


for (int a =n ; n>0; n/=10){
    cout <<  n % 10  ;
    if (n >= 10) cout << ",";
}


bool space = true ;
while (n>0)  {
    if (!space)   cout << ",";
    cout <<  n % 10  ;
    space = false;
  n = n/10 ;
}
  return 0;
}