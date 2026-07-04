#include <bits/stdc++.h>
using namespace std;

void divisor(int n){
    int i = 1;
    bool comma = true;
    while(n>=i){
        if(n%i == 0) {
             if (!comma)cout << ",";
            cout << i ;
         comma = false;
        }
        i++;
    } cout << endl;
}

vector<int> divisors(int n) {
    int i = 1;
    vector <int> v;
while(n>=i){
    if(n%i == 0){
        v.emplace_back(i);
    }
    i++;
    }return v;
}

vector<int> div(int n){
    vector <int> v ;
    // instead of sqrt fun use i*i <=n this wwork same as square root but reduce time complexity of sq fun
    for(int i =1 ;i<=sqrt(n);i++){
        if (n%i == 0){
            v.emplace_back(i);
            if(i!= n/i){
                v.emplace_back(n/i);
            }
        }
    }
    sort(v.begin(),v.end());
    return v;
}

bool prime(int n){
    vector <int> v;
for(int i = 1 ; i*i <=n ; i++){
    if (n%i == 0){
        v.emplace_back(i);
        if(i!=n/i){
            v.emplace_back(n/i);
        }
    }
}
if (v.size() == 2){
    if(v[0] == 1 && v[1] == n)
    return true;
}else return false;
}

bool primee(int n){
    int cnt =0;
   for(int i=1 ; i*i <= n ;i++){
    if (n%i == 0){
        cnt++;
        if(n/i != i){
        cnt++;
    }
    }
   }
   if (cnt ==2) return true;
   else return false;
}

bool prim(int n){
    if (n<=1)return false;
    for (int i = 2 ; i*i <=n ; i++){
        if(n%i == 0) return false;
    } return true;
}
   
int GCD(int n1 ,  int n2){
    int GCD = 1;
    for(int i =1 ; i<=min(n1,n2);i++ ){
        if (n1%i == 0 && n2%i == 0){
            GCD = i;
        }
    }
return GCD;
}

int gcd(int n1 ,int n2){
    for (int i =min(n1,n2); i>0; i--){
        if (n1%i == 0 && n2 %i == 0)
        return i;
    }
}

int euclideanalgo(int n1 ,int n2){
    while( n1>0 && n2>0){
        if (n1>n2) n1 = n1%n2 ;
        else n2 = n2%n1;
    }if (n1 == 0) return n2;
    else return n1;
}

int main() {
    int t;
cin >> t;
for(int i = 0 ; i< t ; i++){
    int n , x ;
    cin >> n >> x;
//   vector <int> v =div(n);
//     bool comma = true;
// //    for(const auto &x : v){
// //         if(!comma) cout<<",";
// //         cout << x ;
// //         comma = false;
//     }
// cout << endl;

int a = euclideanalgo(n ,x);
cout << a << endl;
}
}