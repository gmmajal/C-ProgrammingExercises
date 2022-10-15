#include <iostream>
#include <cmath>
#include <cassert>

int main(int argc, char *argv[]){
    double x[100];
    double x_prev=0.0;
    double x_next,f_x,fprime_x;
    double eps=1e-12;//tolerance values to test: 1e-3,1e-6,1e-12
    x[0]=0.0;

    // for loop with 100 iterations
    for (int i=1;i<=100;++i){
        fprime_x = exp(x[i-1])+3*(x[i-1]*x[i-1]);
        f_x = exp(x[i-1])+(x[i-1]*x[i-1]*x[i-1])-5;
        x[i] = x[i-1] - (f_x/fprime_x);
        if(i>50){
            assert(fabs(exp(x[i])+(x[i]*x[i]*x[i])-5)<1e-6);
        }
        std::cout<<"The value of x is "<<x[i]<<" at iteration "<<i<<" \n";
    }
    std::cout<<"Entering the modified for loop block \n";

    //modfied for loop
    for (int i=1;i<=100;++i){
            fprime_x = exp(x_prev)+3*(x_prev*x_prev);
            f_x = exp(x_prev)+(x_prev*x_prev*x_prev)-5;
            x_next = x_prev - (f_x/fprime_x);
            if(i>50){
                assert(fabs(exp(x_next)+(x_next*x_next*x_next)-5)<1e-6);
            }
            x_prev=x_next;
            std::cout<<"The value of x is "<<x_prev<<" at iteration "<<i<<" \n";
    }
    std::cout<<"Entering the while loop block \n";
    
    x_prev=0.0;
    x_next=1000;
    int count = 0;
    
    //while loop
    while(fabs(x_next-x_prev)>eps){
            if(count ==0){
                fprime_x = exp(x_prev)+3*(x_prev*x_prev);
                f_x = exp(x_prev)+(x_prev*x_prev*x_prev)-5;
                x_next = x_prev - (f_x/fprime_x);
                if(count>100){
                    assert(fabs(exp(x_next)+(x_next*x_next*x_next)-5)<1e-6);
                }
                std::cout<<"The value of x is "<<x_next<<" at iteration "<<count<<" \n";
                count+=1;
            }
            else{
                x_prev=x_next;
                fprime_x = exp(x_prev)+3*(x_prev*x_prev);
                f_x = exp(x_prev)+(x_prev*x_prev*x_prev)-5;
                x_next = x_prev - (f_x/fprime_x);
                if(count>100){
                    assert(fabs(exp(x_next)+(x_next*x_next*x_next)-5)<1e-6);
                }
                std::cout<<"The value of x is "<<x_next<<" at iteration "<<count<<" \n";
                count+=1;
            }
    }
    
    return 0;
}