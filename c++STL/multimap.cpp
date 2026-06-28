#include<bits/stdc++.h>
using namespace std;
int main(){
    multimap<int,  string> mmp ={
        {1,"lalit"},
        {2,"kumar"},
        {1,"striver"},
        {6,"Haryana"},
        {9,"tuf"},
        {9, "tuf"},
    };

    // printing or acessing 

    for (const auto &x : mmp){
        cout << x.first << " " << x.second << endl ;
    }

    auto it = mmp.find(2);
    if (it != mmp.end())
    cout <<"I found : " << (*it).first <<  " " << it -> second << endl;
    else 
    cout << "not found" << endl ;


    //  Insertion

    // mmp[10] ="hy";                                                 //  Not allowed;

    mmp.insert ({7,"Hy"});
    mmp.insert ({7,"Hy"});
    mmp.insert ({7,"Hello"});
    mmp.emplace(5,"Three");

    cout <<"Printing after insertion : "<< endl ;
     for(const auto &x: mmp){
        cout << x.first << " " << x.second << endl;
     }

    //  Deletion 

    mmp.erase(7);
    cout <<"Printing after deletion : "<< endl ;
     for(const auto &x: mmp){
        cout << x.first << " " << x.second << endl;
     }

    auto itt = mmp.find(9);
    mmp.erase(itt);
    cout <<"Printing after deletion with find func : "<< endl ;
    for(const auto &x: mmp){
        cout << x.first << " " << x.second << endl;
     }


    auto x = mmp.begin();
    advance(x,1);
    x = mmp.erase(x);
    cout <<"Deletion using advance fun : "<< x->first << " " << x->second;


    // rest all fun are same as map like .begin() , .end() , clear () etc....

    cout << "I wil print for rest of fun : " << endl;
    cout << mmp.count(9) << " " <<  mmp.empty() << endl ; 



    return 0;
}