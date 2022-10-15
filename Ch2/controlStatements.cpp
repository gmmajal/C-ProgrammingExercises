#include <iostream>

int main(int argc, char* argv[]){
    double p, q, x, y;
    int j;

    //first control statement block
    q = 11; // possible values for q=3,11,11
    p = 11; //possible values for  p=2,12, 11
    j = 20;//possible values for  j=10,20,20
    x = 6;
    std::cout<<"Testing the first control statement block\n";
    if( (p >=q) || (j!=10)){
        x=5;
    }
    std::cout<<"x="<<x<<"\n";
    
    y = 9; //possible values for  y=12,11,11
    j = 10;//possible values for  j=20,10,10
    // second control statement block
    std::cout<<"Testing the second control statement block\n";
    if( (y >=q) && (j==20)){
        x=5;
    }else{
        x=p;
    }
    std::cout<<"x="<<x<<"\n";


    // third control statement block
    std::cout<<"Testing the third control statement block\n";
    if( p > q){
        x = 1;
    }else if((p<=q) && j==10){
        x = 0;
    }else{
        x = 2;
    }
    std::cout<<"x="<<x<<"\n";

    return 0;

}