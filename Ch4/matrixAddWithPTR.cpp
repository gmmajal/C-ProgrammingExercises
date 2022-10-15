#include <iostream>


int main(int argc, char* argv[]){
    
    for(int j=0;j<10000;++j){
        double** A = new double* [2];
        double** B = new double* [2];
        double** C = new double* [2];

        for (int l=0;l<2;++l){
            A[l] = new double[2];
            B[l] = new double[2];
            C[l] = new double[2];
        }

        for (int i=0;i<2;++i){
            for (int k=0;k<2;++k){
                A[i][k] = (double) (i*k)+1;
                B[i][k] = (double) (i*k)+2;
                C[i][k] = A[i][k] + B[i][k];
            }
        }
        std::cout<<"Entries of C\n";
        for (int m=0;m<2;++m) {
            std::cout<<" "<<C[m][0]<< " "<<C[m][1]<<"\n";
        }
        
        for (int nn=0;nn<2;++nn){
            delete[] A[nn];
            delete[] B[nn];
            delete[] C[nn];
        }
        delete [] A;
        delete [] B;
        delete [] C;
    }
    return 0;
}