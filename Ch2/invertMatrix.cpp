#include<iostream>
#include<cmath>
#include<cassert>

int main(int argc, char *argv[]){
    double A [2][2] = {{4,10},{1,1}};
    double Ainv[2][2],tmp[2][2];
    double det = ( (A[0][0]*A[1][1]) - (A[0][1])*A[1][0] );
    assert(det!=0);
    double det_rec=1.0/det;

    for (int i=0;i<2;++i){
        for (int j=0;j<2;++j){
            tmp [i][j]= det_rec * A[i][j];
        }
    }
    Ainv[0][0] = tmp[1][1];
    Ainv[0][1] = tmp[0][1];
    Ainv[1][0] = -tmp[1][0];
    Ainv[1][1] = tmp[0][0];
    
    //print entries of the inverse matrix

    for (int i=0;i<2;++i){
        for (int j=0;j<2;++j){
            std::cout<<"The "<<i<<","<<j<<" entry of the inverse matrix is "<<Ainv [i][j]<<"\n";
        }
    }    
    

    return 0;
}