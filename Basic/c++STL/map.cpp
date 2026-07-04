#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string> mp ;

    // inserting 

    cout << "I will print for insertion : " << endl;

    mp[1] ="Lalit";
    mp[2] = "Lalit";
    mp.emplace(3,"kumar");
    mp.insert({4,"striver"});
    mp.insert({9,"TUF"});
    mp.insert({6,"Haryana"});


    // Acessing/Printing

    cout << "I will print for acess or printing : " << endl;

    for(const auto &x:mp){
        cout<< x.first << " " << x.second << endl ;
    }

    cout << mp[1] << endl ;
    cout << mp[9] << endl ;

    auto it = mp.find(12);
    if(it != mp.end()){
        cout << it -> first << " " << (*it).second ;}
        else{
            cout << "Invalid key";
        }
        cout << endl;
        

        // Deletion

        cout << "I wil print for deletion : " << endl;

        mp.erase(9);
        for (const auto &x : mp){
            cout << x.first << " "<< x.second << " "; 
        }cout << endl;

        auto in = mp.begin();
        advance(in,2);
        mp.erase(in);
        for (const auto &x : mp){
            cout << x.first << " "<< x.second << endl; 
        }


        // Rest all fun ar same as .begin(), .end() , etc....

        cout <<"I am printing output for other fun : " << endl << mp.size() << endl ;
        cout << mp.empty() << endl << mp.count(1) << endl;


    return 0;
}