#include "ComplexNumber.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]){
    std::vector<ComplexNumber> v;
    
    //v.push_back(ComplexNumber(0,0));
    v.push_back(ComplexNumber(-1,-1));
    v.push_back(ComplexNumber(2.5,3.25));
    v.push_back(ComplexNumber(-12.9));
    std::cout<<"The size of the vector v is "<<v.size()<<"\n";
    for(auto i=v.begin();i!=v.end();i++){
        std::cout<<*i<<"\n";
    }
    return 0;
}