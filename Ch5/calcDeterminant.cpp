#include<iostream>
#include<cmath>


double computeDet(double** A, int size){
    int sum=0.0;
    double** subMat= new double* [size-1];
    for (int ss=0;ss<size-1;++ss){
        subMat[ss] = new double [size-1];
    }

    if (size==1){
        for(int zz=0;zz<size-1;++zz){
		delete[] subMat[zz];
	}
	delete[] subMat;
	return A[0][0];
    }else{
        sum=0.0;
        for (int j=0;j<size;++j){
            for (int ii=1;ii<size;++ii){
                for (int jj=0;jj<j;++jj){
                        subMat[ii-1][jj] = A[ii][jj];
                }
                for (int jj=j+1;jj<size;++jj){
                        subMat[ii-1][jj-1] = A[ii][jj];
                }       
            }            
            sum+=pow(-1,j)*A[0][j]*computeDet(subMat ,size-1); 
        }
    }
    for(int zz=0;zz<size-1;++zz){
        delete[] subMat[zz];
    }
    delete[] subMat;
    return sum;
}

int main(){
    int size=2;
    double** A = new double* [size];
    for (int i=0; i<size; ++i){
        A[i] = new double [size];
    }
    A[0][0]=-1.0;A[0][1]=-2.0;
    A[1][0]=3.0;A[1][1]=-7.0;
    double val=computeDet(A,size);

    std::cout<<"The computed determinant is: "<<val<<"\n";
    for (int i=0; i<size; ++i){
        delete[] A[i] ;
    }
    delete[] A;
    return 0;
}
