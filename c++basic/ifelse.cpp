#include<bits/stdc++.h>
using namespace std;
int main(){
    int age;
    cout << "Enter your age : ";
    cin >> age ;
    if (age > 57){
        cout << "Retirment time!!";
    }
    else if (age >= 18 && age <= 57){
        cout << "eligible for job";
        if(age >=55){
            cout << ", but retirment soon!!";
        }
    }
    else{
        cout << "not eligible";
    }
    return 0;
}