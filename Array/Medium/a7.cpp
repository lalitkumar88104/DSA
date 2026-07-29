#include<bits/stdc++.h>
using namespace std;

// next permutation

// brute force sol : using recursion or loop (find all possible permutation and return the next permutation of given no if not present return 1st possible one)
// didnt work on brute now as striver didnt too but i wil definately soon from recursion playlist of striver 

// better 
vector <int> better (vector <int> &no){
    // do{
    //     for(auto it : no){
    //     cout << it << " ";               // this code will find all possible next permutation need further work to give next 
    // }cout << endl;
    // }
    // while( next_permutation(no.begin() , no.end());
    next_permutation(no.begin() , no.end());
    return no;
}

// optimal 

vector <int> optimal (vector <int> & no){           //tc = O(3n) ; sc =O(1)
    int index = -1;
    int n = no.size();
    for(int i = n-2 ; i>= 0 ; i-- ){
        if(no[i] < no[i+1]){
            index = i;
            break;
        }
    }
    if (index == -1){
        reverse(no.begin() , no.end());
        return no;
    }
    for(int i = n-1 ; i>index ; i--){
        if(no[i]>no[index]){
            swap(no[i] , no[index]);
            break;
        }
    }
    reverse(no.begin()+index+1 , no.end());
    return no;
}

int main(){
    vector<int> nums = {2, 1, 5, 4, 3 , 0, 0};

    vector<int> result = optimal(nums);

    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}