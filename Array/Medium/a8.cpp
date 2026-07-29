#include<bits/stdc++.h>
using namespace std;

// leaders in an array : leaders tends to that elements in which everything on the right should be larger

// brute 
vector <int> brute (vector<int> arr ){             // tc = O(n*n) ; sc = O(n)fo returning the ans;
    int n = arr.size();
    vector<int> ans;
    for(int i = 0 ; i<n ; i++){
        bool leader = true;
        for(int j = i+1 ; j < n ; j++){
            if (arr[i] < arr[j]){
                leader = false;
                break;
            }
        }
        if (leader == true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

// optimal

vector<int> optimal (vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = n-1 ; i>= 0 ; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return ans;
}
int main(){
    vector<int> arr ={10 , 22 , 12 ,14 , 13 , 0 , 6};
    vector <int> ans = optimal(arr);
    for (auto it : ans){
        cout << it << " ";
    }
    return 0;
}