#include<bits/stdc++.h>
using namespace std;

// rearange array elements by sign : there will be n elements in which n/2 is +ve and n/2 is -ve
// rearange them in order that first +ve than -ve and so on

// brute sol
void brute (int arr[] , int n){    // tc = O(2n) ; sc = O(n);
    vector <int> positive;
    vector <int> negative;
    for (int i = 0 ; i < n ; i++){
        if (arr[i] >= 0){
            positive.push_back(arr[i]);
        }
        else {
            negative.push_back(arr[i]);
        }
    }
    for(int i = 0 ; i<n ; i++){
        if (i%2 == 0){
            arr[i] = positive[i/2];
        }
        else{
            arr[i] = negative[i/2];
        }
    }
}

// better will work only and only if there are even no of elements (ex n = 6,8,10) it will ot work fo odd (n = 3 , 5, 7)
// better sol;
void better(int arr[] , int n){   // tc = O(n) + O(2/n) ; sc = O (n);
    vector <int> positive;
    vector <int> negative;
    for(int i = 0 ; i< n ; i++){
        if (arr[i] >= 0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }
    for(int i = 0 ; i<n/2 ; i++){
        arr[2*i] = positive[i];
        arr[2*i+1] = negative[i];
    }
}

//optimal sol
void optimal ( int arr[] , int n){     // tc = O(n); sc =(n);
    vector <int> ans(n);
    int positive = 0;
    int negative = 1;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] < 0){
            ans[negative] = arr[i];
            negative+=2;
        }
        else{
            ans[positive] = arr[i];
            positive+=2;
        }
    }
    for(const auto x: ans){
        cout << x << " ";
    }
}



// variety 2 of same q : int his variaton there is no garuntee that how +ve and -ve no are same in counting there can
// be possibibility that there is only 1 +ve no and 9 -ve no so rearreange array by sign without altering order 
// if any no left place it at back in same order

vector <int> optimalvariation2(vector <int> ans, int n){        // tc = O(2n) ; sc =O(n);
    vector<int> positive;
    vector <int > negative;
    for(int i = 0 ; i<n ; i++){
        if(ans[i] <0){
            negative.push_back(ans[i]);
        }
        else{
            positive.push_back(ans[i]);
        }
    }
    if (positive.size() > negative.size()){
        for(int i = 0; i < negative.size() ; i++){
            ans[2*i] = positive[i];
            ans[2*i+1] = negative[i];
        }
        int index = negative.size();
        for(int i = 2*negative.size() ; i < n ; i++){
            ans[i] = positive[index++];
        }
    }
    else {
        for(int i = 0; i < positive.size() ; i++){
            ans[2*i] = positive[i];
            ans[2*i+1] = negative[i];
        }
        int index = positive.size();
        for(int i = 2*index ; i < n ; i++){
            ans[i] = negative[index++];
        }
    }
    return ans;
}
int main (){

    int arr[] = {3, 1, -2, 2, -5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // brute(arr, n);

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    cout <<  endl;
    optimal(arr , n);

    vector<int> ans = {3, 1, -2, -5, 2, -4, 7};

    int n = ans.size();

    vector<int> result = optimalvariation2(ans, n);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}