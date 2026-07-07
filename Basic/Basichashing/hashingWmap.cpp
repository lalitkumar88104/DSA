#include<bits/stdc++.h>
using namespace std;

int main(){
    int num ;
    cout << "Enter total no of no's present : ";
    cin >> num;
    int arr[num];
    for(int i= 0 ; i<num ; i++){
        cin >> arr[i];
    }
    // precompute 

    map<int ,int> frequency;
    for(int i=0 ; i<num ; i++){
        frequency[arr[i]]++;
    }
    
    //  fetching

    int quuery;
    cout << "Enter no of query : ";
    cin >> quuery;
    while(quuery--){
        int n;
        cout << "Enter query no : ";
        cin >> n;
        cout << frequency[n] << endl ;
    }
    return 0;
}