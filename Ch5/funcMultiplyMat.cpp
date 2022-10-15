#include <iostream>
#include <cassert>


void Multiply(double** A, double** B, double** C,int rowsA, int colsA,  int rowsB, int colsB){
    assert(colsA==rowsB);
    for(int i=0;i<rowsA;++i){
        for(int k=0;k<colsB;++k){
            double sum=0.0;
            for(int j=0;j<rowsB;++j){
                sum+=A[i][j]*B[j][k];
            }
            C[i][k]=sum;
        }
    }
}

int main(){
    int row_A = 2;
    int col_A = 3;
    
    int col_B = 2;
    
    double** A = new double* [row_A];
    double** B = new double* [col_A];
    double** C = new double* [row_A];
    for (int i=0; i<row_A; ++i)
    {
        A[i] = new double [col_A];
        C[i] = new double [col_B];
    }
    for(int j=0;j<col_A;++j){
        B[j]=new double [col_B];
    }

    A[0][0]=1.0; A[0][1]=2.0; A[0][2]=0.0; 
    A[1][0]=1.0; A[1][1]=2.0; A[1][2]=0.0; 

    B[0][0]=1.0; B[0][1]=2.0;
    B[1][0]=1.0; B[1][1]=2.0;
    B[2][0]=1.0; B[2][1]=2.0;

    
    Multiply( A,B,C,row_A,col_A,col_A,col_B);
    std::cout<<"C is\n";
    std::cout<<C[0][0] <<" "<< C[0][1]<<"\n";
    std::cout<<C[1][0] <<" "<< C[1][1]<<"\n";
    
    for (int i=0; i<row_A; i++){
        delete[] A[i] ;
        delete[] C[i] ;
    }
    for(int j=0;j<col_A;++j){
        delete[] B[j];
    }
    delete[] A;
    delete[] B;
    delete[] C;


    return 0;
}
