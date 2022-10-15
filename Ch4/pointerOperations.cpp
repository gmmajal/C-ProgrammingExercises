#include<iostream>

int main(int argc, char* argv[]){
    int i=5;
    int* p_j;

    p_j=&i;
    std::cout<<"i="<<i<<"\n";
    std::cout<<"p_j="<<*p_j<<"\n";
    *p_j *=5;
    std::cout<<"i="<<i<<"\n";
    std::cout<<"p_j="<<*p_j<<"\n";
    int* p_k = new int;
    *p_k=i;
    
    std::cout<<"i="<<i<<"\n";
    std::cout<<"p_k="<<*p_k<<"\n";
    

    *p_j=0;
    std::cout<<"i="<<i<<"\n";
    std::cout<<"p_j="<<*p_j<<"\n";
    std::cout<<"p_k="<<*p_k<<"\n";
    delete p_k;
}
