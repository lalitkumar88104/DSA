#include<bits/stdc++.h>
using namespace std; 

bool compp(pair<int,string> p1 , pair<int,string>p2){
    if(p1.first>p2.first) return true;
    else if (p1.first<p2.first) return false;
    else if(p1.first == p2.first){
        if (p1.second > p2.second) return true;
        else return false;
    }
}


bool comp(pair<int,int> p1 , pair<int,int>p2){
    if(p1.first>p2.first) return true;
    else if (p1.first<p2.first) return false;
    if(p1.first == p2.first){
        if (p1.second > p2.second) return true;
        else return false;
    }
}
int main (){

    vector<int> v ={98,23,55,74,234,6,775,45,23};

    // sort = use  for sorting an container in ascending order

    cout << "Before Sorting" << endl ;
    for(const auto &x : v){
        cout << x << " ";
    }cout << endl;

    sort(v.begin() , v.end()); 

    cout << "After Sorting :" << endl ;
    for(const auto &x : v){
        cout << x << " ";
    }cout << endl;

    // sorting in  descending order for descending use greater<int> in last

    // sorting of a part for ex first 3 elements
    sort(v.begin(),v.begin()+4 ,greater<int>());
    cout << "After Sorting in descending order for first 4 element : " << endl ;
    for(const auto &x : v){
        cout << x << " ";
    }cout << endl;

    // sorting full vector
    sort(v.begin(),v.end() ,greater<int>());
    cout << "After Sorting in descending order : " << endl ;
    for(const auto &x : v){
        cout << x << " ";
    }cout << endl;



    // lower_bound

    cout << "Printing for lower_bound"<< endl ;
   sort(v.begin() , v.end()); 
   int index = lower_bound(v.begin(),v.end(),74) - v.begin();
   cout << v[index] << endl ; 


    vector<int>:: iterator it = lower_bound(v.begin(),v.end(),100);
    if(it != v.end()){
        cout << *it << endl;
    }
    else
    cout << "Not present neither nor nor just greater than it "<< endl ;


    // Upper_bound

     cout << "Printing for upper_bound"<< endl ;
    auto ind = upper_bound(v.begin(),v.end(), 999) - v.begin();
    if (ind != v.size())
    cout << v[ind] << endl;
    else
    cout << "returning end()"<< endl;


    // comp or comperator


    pair<int,string> pp[] = {
        {1,"hy"},
        {1,"hy"},
        {1,"hello"},
        {19,"how"},
        {8,"string"},
        {5,"boolean"},
    };

    cout << "Printing pair : "<< endl ;
    for(const auto &x: pp){
        cout << x.first << " " << x.second << ", ";
    }
    cout << endl << "I am sorting using comp or sorting in my way :" << endl;
    int nn = sizeof(pp) / sizeof(pp[0]);
    sort(pp , pp+nn , compp);
    for(const auto &x: pp){
        cout << x.first << " " << x.second << ", ";
    }cout << endl;

    pair<int,int> p[] = {
        {1,5},
        {1,2},
        {1,5},
        {19,6},
        {8,9},
        {5,5},
    };

    cout << "Printing pair : "<< endl ;
    for(const auto &x: p){
        cout << x.first << " " << x.second << ", ";
    }
    cout << endl << "I am sorting using comp or sorting in my way :" << endl;
    int n = sizeof(p) / sizeof(p[0]);
    sort(p , p+n , comp);
    for(const auto &x: p){
        cout << x.first << " " << x.second << ", ";
    } cout << endl;

    // Reverse


    sort(p , p+n);
    cout << "printing after sorting pair: " << endl ;
    for(const auto &x: p){
        cout << x.first << " " << x.second << ", ";
    }cout << endl;
    reverse(p , p+n);
    cout << "printing after reverse : " << endl ;
    for(const auto &x: p){
        cout << x.first << " " << x.second << ", ";
    }cout << endl;


    // max_element 
    cout << "i will print Max element : " << endl ;
    auto itt = max_element(p,p+n);
    cout << (*itt).first << " " << itt -> second << endl ;

    // Min element 
    cout << "i will print Min element in vector  : " << endl ;
    auto ittt = min_element(v.begin(),v.end());
    cout << *ittt << endl;

    // Accumulator

    cout <<"i will prinnt accumulate value : " << accumulate(v.begin() , v.end(),0) << endl;

    // __builtin_popcount
    cout << "I will print for popcount : " << __builtin_popcount(14) << endl ;  // work on integer value only not on whole container

    // next_permutation

    string s = "123";
    cout << "next permutation of 123 : ";
    do{
        cout << s << " ";
    } while(next_permutation(s.begin() , s.end()));

    // prev permutation

    string a = "213" ;
    cout << endl << "prev permutation of 213 : ";
    do{
        cout << a << " " ;
    }while (prev_permutation(a.begin()  ,  a.end()));
    return 0;
}