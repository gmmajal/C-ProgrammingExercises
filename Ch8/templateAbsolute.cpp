#include <iostream>
#include <cmath>

template<class T> T getAbsolute (T num1);

int main(int argc, char* argv[]){
    int i = -4;
    double d = -2.5;
    long l = -24509191;
    long double ld = -24509191.2567;
    
    //Test using int
    std::cout<<"The int (i) value is "<<i<<"\n";
    int i_abs = getAbsolute<int>(i);
    std::cout<<"The absolute (|i|) value is "<<i_abs<<"\n";
    
    //Test using double
    std::cout<<"The double (d) value is "<<d<<"\n";
    double d_abs = getAbsolute<double>(d);
    std::cout<<"The absolute (|d|) value is "<<d_abs<<"\n";

    //Test using long
    std::cout<<"The long (l) value is "<<l<<"\n";
    long l_abs = getAbsolute<long>(l);
    std::cout<<"The absolute (|l|) value is "<<l_abs<<"\n";

    //Test using long double
    std::cout<<"The long double (ld) value is "<<ld<<"\n";
    long double ld_abs = getAbsolute<long double>(ld);
    std::cout<<"The absolute (|ld|) value is "<<ld_abs<<"\n";

    return 0;
}

template <class T> T getAbsolute(T num1){
    return std::abs(num1);
}