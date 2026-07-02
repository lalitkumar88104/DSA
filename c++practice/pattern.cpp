#include<bits/stdc++.h>
using namespace std;


void pq4(int n){
        int space = n ;
        for(int i = 1 ; i<=n ; i++){
            // space
            for (int j = 1 ; j <= space-i ; j++){
                cout << " ";
            } 
            

            // star
            for ( int j= 1 ; j<= (2*i)-1 ; j++){
                cout << "*";
            }
            cout << endl;
        }
        int star = 2*(n-1) ;
        for(int i =1 ; i<n ; i++){
            for (int j = 1 ; j<=i ; j++){
                cout << " ";
            }
            for (int j = 1 ; j< star ; j++ ){
                cout << "*";
            }star = star-2;
            cout << endl;
        }
    }


void pq4_2(int n){
 for (int i = 1; i <= 2*n-1 ; i++ ){
    // space
    int space = n-i;
    if (i>n)space = abs(n-i);
    for(int j=1 ; j <= space ; j++){
        cout << " ";
    }
    // stars
    int stars = (2*n-1) - 2*abs(n-i);
    for (int j= 1 ; j<= stars ; j++){
        cout << "*";
    }cout << endl; 
 }
}

int count (int n){
    int a = 0;
    do {
        n/=10 ;
        a++;
    }while (n > 0);
    return a ;
}

int rev(int n){
    int a = 0;
    while (n>0){
    //     if(n%10 ==0){
    //         n/=10;
    //     }
        a = (a * 10) + (n%10) ;
        n/=10;
        
    }
    return a;
}

bool pal(int n){
    cout << boolalpha;
    int temp =n;
    int rev = 0 ;
    while (temp>0){
        rev = (rev*10) + (temp%10);
        temp/=10;
    }
    if (n == rev) return true;
    else return false;
}

bool armstrong(int n){
    cout << boolalpha;
int dup = n;
int dup1 =n ;
int v = 0;
int a = 0;
while(dup1 >0){
    dup1/=10;
    a++;
}
while (dup>0){
  v =(int)( v + (pow(dup%10 , a) ));
  dup/=10;
}
// while (dup > 0) {
//     cout << "digit = " << dup % 10 << endl;
//     cout << "power = " << pow(dup % 10, a) << endl;

//     v += pow(dup % 10, a);

//     cout << "v = " << v << endl;

//     dup /= 10;
// }
  return v == n;
}


int main (){

int t;
cin >> t;
for(int i = 0 ; i< t ; i++){
    int n ;
    cin >> n;
    bool a = armstrong(n);
    cout << a << endl;
}
// cout << typeid(pow(153%10 , 2) ).name();
    return 0;
}