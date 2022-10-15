#include <iostream>


int main(int argc, char* argv[]){
    
    for(int j=0;j<10000;++j){
        double* vec1 = new double [3];
        double* vec2 = new double [3];

        for (int i=0;i<3;++i){
            vec1[i] =  (double) i*0.5;
            vec2[i] =  (double) i*0.1;
        }

        double dotProd = (vec1[0] * vec2[0])+ (vec1[1]*vec2[1])+(vec1[2]*vec2[2]);
        std::cout.precision(4);
        std::cout<<"The dot product is "<<dotProd<<"\n";
        
        delete [] vec1;
        delete [] vec2;
    }
    return 0;
}