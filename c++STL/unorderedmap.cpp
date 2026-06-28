#include<bits/stdc++.h>
using namespace std;
int main() {

    unordered_map<string,int> um = {
        {"Lalit" , 1},
        {"Lalit", 2},
        {"kumar", 3},
        {"striver",3},
    };

    // Printing 

    cout << "printing : " << endl;
    for (const auto &x : um){
        cout<< x.first <<" " << x.second << endl;
    }

    cout << "printing value with key : "<< um["Lalit"] << endl;    // printing with key


    cout << "printing with find : "<< endl;
    auto x = um.find("kumar");
    if(x != um.end())
    cout << x -> first << " " << x -> second << endl;



    // Insertion 


    um["ram"] = 1;

    um.emplace("Haryana" , 2);
    um.insert({"Gurgaon", 5});

       cout << "printing after insertion : " << endl;
    for (const auto &x : um){
        cout<< x.first <<" " << x.second << endl;
    }



    // deletion 


    um.erase("ram");            // erase using key
       cout << "printing after deletion : " << endl;
    for (const auto &x : um){
        cout<< x.first <<" " << x.second << endl;
    }

    auto it = um.find("2");         // Erase using find fun
    if(it != um.end())
    cout << it -> first << " " << it -> second << endl;
    else 
    cout << "Not found" << endl;

    unordered_map<string,int>:: iterator y = um.begin();            // deletion with advance fun
    advance(y,2);
    um.erase(y);
    for (const auto &x : um){
        cout<< x.first <<" " << x.second << endl;
    }


    //Rest all fun are same as map

    cout << "i will print for extra fun : " << endl;
    cout << um.empty() << endl << um.count("3") <<endl << um.size();    

    return 0;
}