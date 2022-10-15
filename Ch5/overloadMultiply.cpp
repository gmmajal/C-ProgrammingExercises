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

void Multiply(double* u, double* v, double** A,  int rowsA, int colsA, int rowsU){
    assert(colsA==rowsU);
    for (int i=0;i<rowsA;++i){
        double sum =0.0;
        for (int j=0;j<colsA;++j){
            sum+=A[i][j]*u[j];
        }
        v[i]=sum;
    }
}

void Multiply(double** A, double* u, double* v, int rowsA, int colsA, int rowsU){
    assert(colsA==rowsU);
    for (int i=0;i<rowsA;++i){
        double sum =0.0;
        for (int j=0;j<colsA;++j){
            sum+=A[i][j]*u[j];
        }
        v[i]=sum;
    }
}

void Multiply(double alpha, double** A,int rowsA, int colsA){
    for (int i=0;i<rowsA;++i){
        for (int j=0;j<colsA;++j){
            A[i][j]=alpha*A[i][j];
        }
    }
}

void Multiply(double**A, double alpha, int rowsA, int colsA){
    for (int i=0;i<rowsA;++i){
        for (int j=0;j<colsA;++j){
            A[i][j]=alpha*A[i][j];
        }
    }
}

int main(int argc, char* argv[]){
    int row_A = 2;
    int col_A = 3;
    
    int col_B = 2;
    
    double** A = new double* [row_A];
    double** B = new double* [col_A];
    double** C = new double* [row_A];
    double* u= new double [col_A];
    double* v= new double [row_A];
    double alpha= 1.5;

    for (int i=0; i<row_A; ++i)
    {
        A[i] = new double [col_A];
        C[i] = new double [col_B];
    }
    for(int j=0;j<col_A;++j){
        u[j] = j+1;
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

    Multiply( A,u,v, row_A,col_A,col_A);
    std::cout<<"v is\n";
    std::cout<<v[0] <<" "<< v[1]<<"\n";
    
    Multiply(u,v,A, row_A,col_A,col_A);
    std::cout<<"v is\n";
    std::cout<<v[0] <<" "<< v[1]<<"\n";

    Multiply( alpha,A,row_A,col_A);
    std::cout<<"A is\n";
    std::cout<<A[0][0] <<" "<< A[0][1]<<" "<<A[0][2]<<"\n";
    std::cout<<A[1][0] <<" "<< A[1][1]<<" "<<A[1][2]<<"\n";

    Multiply( A,alpha,row_A,col_A);
    std::cout<<"A is\n";
    std::cout<<A[0][0] <<" "<< A[0][1]<<" "<<A[0][2]<<"\n";
    std::cout<<A[1][0] <<" "<< A[1][1]<<" "<<A[1][2]<<"\n";

    
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
    delete[] u;
    delete[] v;
    
    return 0;
}