#include <iostream>

int changeNumVal(int* p){
    *p = 1;
    return *p;
}

int main(){
    int num =3;
    std::cout<<"num ="<<num<<"\n";
    num=changeNumVal(&num);
    std::cout<<"num ="<<num<<"\n";
    return 0;
}