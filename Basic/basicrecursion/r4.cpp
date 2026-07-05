#include<bits/stdc++.h>
using namespace std;

void reverse(array<int,5> &a , int i , int n){
    if (i>=n){
        cout << "aray after reversing : ";
        for(const auto &x : a){
            cout << x << " ";
        } return ;
    }
    swap(a[i],a[n]);
    reverse(a ,i+1 ,n-1) ;
}


int main (){
array <int,5>arr = {10,20,30,40,50};
cout << "array before reversing : ";
for(const auto &x : arr){
    cout << x << " " ;
}cout << endl;
reverse(arr,0,arr.size()-1);

    return 0;
} 