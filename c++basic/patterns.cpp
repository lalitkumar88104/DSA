#include<bits/stdc++.h>
using namespace std;

void p3(int n){;
    for (int i = 0 ; i < n ; i++){
        for (int j =0 ; j <=i ; j++){
            int a ;
            a = j + 1 ;
            cout << a ;
        }
        cout << endl ;
    }
}

void p4(int n){
    for (int i = 1 ; i <=n ; i++){
        for(int j = 1 ; j<=i ; j++){
            cout << i ;
        }
        cout << endl;
    }
}

void p5(int n){
    for (int i = n ; i >= 1; i--){
        for(int j = i ; j>=1 ; j--){
            cout << "*";
        }
        cout << endl;
    }
}

void p6(int n){
    for(int i =n ; i>0 ; i--){
        for(int j = 1; j<= i ; j++){
            cout << j;
        }
        cout << endl ;
    }
}

void p7(int m){
    for(int i = 1 ; i <= m ; i++){
         int k ;
            for(k = 0 ; k< m-i ; k++){
                cout << " ";
            }
        for(int j = 1; j <= i+i-1 ; j++){
                cout << "*" ;
        }

            for(k = 0 ; k< m-i; k++){ //optional for loop
                cout << " ";
            }
        cout << endl;
    }

}

void p8(int n){
    for(int i =n ; i> 0 ; i--){
        for(int j =1 ; j<= n-i ; j++){
            cout << " ";
        }
        for (int j =1 ; j<=i*2-1 ; j++){
            cout << "*" ;
        }
        cout << endl;
    }


}

// p9 is combination od p7 and p8

void p10(int n){
    for(int i = 1; i<= 2*n ; i++){
     int stars =i;
     if (i > n) stars = 2*n -i;
        for (int j = 1 ; j<= stars ; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void p11(int n){
int start;
    for (int i = 1; i <= n ; i++){
        if (i % 2 == 0) start = 0;
        else start = 1;
        for (int j =1 ; j <= i ; j++){
            cout << start << " " ;
            start = 1 - start ;
        }
        cout<< endl;
    }
}

void p12(int n){
    for (int i = 1 ; i<= n ;i++){
        for (int j =1 ; j <= i ; j++){
            cout << j;
        }
        for (int j = 1 ; j <= 2*n -(2*i) ; j++){
            cout << " ";
        }
        for (int j = i ; j>=1 ; j--){
            cout << j;
        }
        cout << endl ;
    }
}

void p13(int n){
    int num = 1;
    for (int i = 1 ; i<= n ; i++){
        for (int j = 1 ; j <= i ; j++){
            cout <<  num << " " ;
            num ++ ; 
        }
        cout << endl ; 
    }
}

void p14(int n){
    for (int i = 1 ; i <= n ; i++){
         char c = 'A';
        for (int j = 1 ; j <= i ; j++){
            cout << c << " ";
            c++;
        }
        cout << endl;
    }
}

void p15(int n){
for(int i = 0 ; i <n ; i++){
    
    for (char a  = 'A' ; a <  'A' + (n -i) ; a++){
        cout << a ;
    }
    cout << endl;
}
}

void p16(int n){
    char c = 'A';
    for (int i = 0 ; i < n ; i++){
        
        for (int j = 0 ; j <=i ; j++){
            cout  << c;
        }
        cout << endl;
        c++;
    }
}

void p17(int n){
    for (int i = 0 ; i <n ; i++){
        char c = 'A';
        // space
        for (int j =0 ; j < n- i -1 ; j++){
            cout << " ";
        }
        // value
        for (int j = 0 ; j <i+i+1 ; j++){
            cout << c;
            if (j<i) { // or j < ((2*i + 1) /2 ) whic is equal to 0 
                c++;
            }
            else {
                c--;
            
            }
            
        }
        cout<< endl;
    }
}

void p18(int n){
    for(int i = 0 ; i<n ; i++){
        char c = 'A'+ n-i -1 ;
        for ( c ; c <= 'A'+(n-1); c++){
            cout << c;
        }
        cout << endl;
    }
}

void p19(int n){
    for ( int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n-i; j++ ){
            cout << "*";
        }
        for (int j = 0 ; j < 2*i ; j++){
            cout << " ";
        }
        for (int j = 0 ; j<n-i; j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i = n ; i> 0 ; i--){
        for (int j = 0; j< n-i+1; j++){
            cout << "*";
        }
        for(int j = 0 ; j< 2*(i-1); j ++){
            cout<< " ";
        }
        for(int j=0 ; j<n-i+1; j++){
            cout << "*";
        }
        cout<< endl;
    }

}

void p20(int n){
    for (int i=1 ; i<= 2*n-1 ; i++) {
        // star
        int star = i;
        if (i > n ) star = 2*n -i;
        for (int j =1 ; j<= star; j++){
            cout<< "*";
        }
        // space 
        int space = 2*(n-i);                //
        if ( space < 0) {                   // we can use this also instead 
            space = space + (-2* space);    //int space = 2 * abs(n - i);
        }                                   //              
        for (int j =1 ; j<=space ; j++){
            cout << " ";
        }

        // star
       
    
        for (int j =1 ; j<= star; j++){
            cout<< "*";
        }
        cout << endl;
    }
}

void p21(int n){
for (int i = 1 ; i <= n ;i++){
    
   for (int j =1 ; j<=n ; j++){
    if ( i == 1 || i == n || j == 1 || j == n ){
        cout << "*";
    }
    else{
        cout<< " ";
    }}
    cout<< endl;
}
}

void p22(int n){
    for (int i =0 ; i<2*n-1 ; i++){
        for (int j= 0 ; j<2*n-1 ; j++){
            int top = i;
            int left = j;
            int bottom = (2*n -2) -i;
            int right = (2*n- 2)-j;
            cout << (n-min(min ( top , bottom),min(left,right)));
        }
        cout << endl ;
    }
}

int main (){
int t;
cin >> t;
for(int i = 0 ; i< t ; i++){
    int n ;
    cin >> n;
    p22(n);
}
    return 0;
}