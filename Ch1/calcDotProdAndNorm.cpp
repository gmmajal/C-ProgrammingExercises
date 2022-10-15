#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
    
    double vec1[3]={3.1,4.5,6.7};
    double vec2[3]={2.1,7.8,9.1};

    double dotProd= (vec1[0]*vec2[0]) + (vec1[1]*vec2[1]) + (vec1[2]*vec2[2]);
    double euclidNormVec1= sqrt((vec1[0]*vec1[0])+(vec1[1]*vec1[1])+(vec1[2]*vec1[2]));
    double euclidNormVec2= sqrt((vec2[0]*vec2[0])+(vec2[1]*vec2[1])+(vec2[2]*vec2[2]));

    std::cout<<"The first vector is : ["<<vec1[0]<<","<<vec1[1]<<","<<vec1[2]<<"]\n";
    std::cout<<"The second vector is: ["<<vec2[0]<<","<<vec2[1]<<","<<vec2[2]<<"]\n";
    std::cout<<"Their dot product is: "<<dotProd<<"\n";
    std::cout<<"The Euclidean norm of the first vector is: "<<euclidNormVec1<<"\n";
    std::cout<<"The Euclidean norm of the second vector is: "<<euclidNormVec2<<"\n";

    return 0;
}