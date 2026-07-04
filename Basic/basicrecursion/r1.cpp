#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void print(){

    // Base case 

    if (cnt == 5) return;

    // Work 

    cout << cnt  << " ";
    cnt ++;

    // recursive call

    print();
    
}

void printt (int n){
    if (n == 0) return;
    cout << n << " ";
    printt (n-1);
cout << n << " ";
}

void fun(int n){

    if(n==0)
        return;

    fun(n-1);

    cout<<n<<" ";
}
int main(){
   fun(10) ; 
    printt(7);
    return 0;
}