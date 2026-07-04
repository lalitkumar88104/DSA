// program for taking input ant output
#include<iostream>

int main(){
    std::cout << "hy lalit! ";
    std::cout << "hy lalit! " << "\n" << "for next line we can use std::endl to" << std::endl;  
    std::cout << "hy lalit! "; 
// for using functions like cout and cin we need to use stdd:: before these functions as these functions come under std::
int x , y;
 std::cin >> x >> y;
 std::cout <<"value of x is : " << x << " and y is : " << y ;
 return 0;
}

// here writing std:: is so frustating therefor we use using name space std ;
