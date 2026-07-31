#include<bits/stdc++.h>
using namespace std;

// maximum consecutive subsequence = means max length of no in order like 102 ,103 ,104 ,105 or 1,2,3,4

// brute
int brute (vector <int> arr){          // tc = O(nlogn + n*n) ; sc = O(1)
    int n = arr.size();
    
    int maxlength = 1;
    sort(arr.begin() , arr.end());
    for(int i =0 ; i<n ; i++){
        int length = 1;
        for(int j = i ; j<n-1 ; j++){
            if(arr[j] + 1 == arr[j+1]){
                length++;
                maxlength = max(maxlength , length);
            }
            else if (arr[j] == arr[j+1])
            {
                continue;
            }
            
            else {
                length = 1;
            }
        }
    }
    return maxlength;
}

// brute better
//helper fun:
bool ls (vector <int> arr ,int target){
    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}
int brutebetter(vector <int> arr){          // tc = O(n*n)  ; sc = O(1);
    int maxlength = 1 ;
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        int count = 1;
        int x = arr[i];
        while(ls(arr , x+1)){
            x = x+1;
            count += 1;
            maxlength = max(maxlength , count);
        }
    }    
    return maxlength;
}


// better ;

int better (vector <int> arr){              // tc = O(nlogn + n) ; sc = O(1)
    int n = arr.size();
    int count = 0;
    int maxlength = 1;
    int lastelement = INT_MIN;
    sort(arr.begin() , arr.end());
    for (int i = 0 ; i < n ; i++){
        if (arr[i] -1 == lastelement){
            count++;
            lastelement = arr[i];
            maxlength = max (maxlength , count);
        }
        else if( arr[i] == lastelement){
            continue;
        }
        else{
            lastelement = arr[i];
            count = 1;
        }
    }
    return maxlength;
}

// or
int striverbetter (vector <int> arr){
    int n = arr.size();
    int count = 0;
    int maxlength = 1;
    int lastelement = INT_MIN;
    sort(arr.begin() , arr.end());
    for (int i = 0 ; i < n ; i++){
        if (arr[i] -1 == lastelement){
            count++;
            lastelement = arr[i];
        }
        else if( arr[i] != lastelement){
            lastelement = arr[i];
            count = 1;
        }
        maxlength = max (maxlength , count);
    }
    return maxlength;
}

// optimal ; 



int main(){
    vector<int> arr ={102,4,100,101,3,2,1,1};
    cout << better(arr);
    return 0;
}