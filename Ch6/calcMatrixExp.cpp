#include "ComplexNumber.hpp"
#include <iostream>

long long int fact(int n){
	if (n==0){
		return 1;
	}else{
		return n*fact(n-1);
	}
}

void matMult(ComplexNumber** A, ComplexNumber** B, ComplexNumber** C){
	for(int i=0;i<3;++i){
		for (int k=0;k<3;++k){
			ComplexNumber sum(0.0,0.0);
			for(int j=0;j<3;++j){
				sum = sum + (A[i][j]*B[j][k]);
			}
			C[i][k] = sum;
		}
	}
}

void matPower(ComplexNumber** mat, ComplexNumber** resultMat, int power){
	ComplexNumber** tempMat;
	tempMat = new ComplexNumber* [3];
	for(int i=0;i<3;++i){
		tempMat[i] = new ComplexNumber [3];
	}
	if(power==0){
		for (int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				if(i==j){
					resultMat[i][j]=ComplexNumber(1.0);
				}else{
					resultMat[i][j]=ComplexNumber(0.0);
				}
			}
		}
	}else{
		for (int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				resultMat[i][j] = mat[i][j];
				tempMat[i][j] = mat[i][j];
			}
		}
		for (int i=0;i<power-1;++i){
			matMult(mat,tempMat,resultMat);
			for (int j=0;j<3;++j){
				for(int k=0;k<3;++k){
					tempMat[j][k] = resultMat[j][k];
				}
			}
		}
	}
	for(int i=0;i<3;++i){
		delete[] tempMat[i];
	}
	delete[] tempMat;
}

void expMatrix(ComplexNumber** A, ComplexNumber** B){
	ComplexNumber** sumMat;
	sumMat = new ComplexNumber* [3];
	for(int i=0;i<3;++i){
		sumMat[i] = new ComplexNumber [3];
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			sumMat[i][j] = ComplexNumber(0,0);
		}
	}
	for(int n=0;n<20;++n){
		matPower(A,B,n);
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				double rp = B[i][j].getRealPart()/double(fact(n));
				double ip = B[i][j].getImaginaryPart()/double(fact(n));
				sumMat[i][j] = sumMat[i][j] + ComplexNumber(rp, ip);
			}
		}
	}
	for (int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			B[i][j] = sumMat[i][j];
		}
	}
	for(int i=0;i<3;++i){
		delete[] sumMat[i];
	}
	delete[] sumMat;
}
int main(int argc, char* argv[]){
	ComplexNumber z1(2.0);
	ComplexNumber z2(0.0,0.0);

	ComplexNumber** mat = new ComplexNumber* [3];
	ComplexNumber** matExp = new ComplexNumber* [3];

	for (int i=0;i<3;++i){
		mat[i] = new ComplexNumber[3];
		matExp[i] = new ComplexNumber[3]; 
	}
    
	for (int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			mat[i][j] = z1;
		}
	}    
	expMatrix(mat, matExp);

	//Print matrix
	std::cout<<"Exponential Matrix is \n";
	std::cout<<matExp[0][0]<<" "<<matExp[0][1]<<" "<<matExp[0][2]<<"\n";
	std::cout<<matExp[1][0]<<" "<<matExp[1][1]<<" "<<matExp[1][2]<<"\n";
	std::cout<<matExp[2][0]<<" "<<matExp[2][1]<<" "<<matExp[2][2]<<"\n";

	//deallocate memory
	for(int i=0;i<3;++i){
		delete[] mat[i];
		delete[] matExp[i];
	}
	delete[] mat;
	delete[] matExp;

	//Special case
	std::cout<<"Testing special case\n";
	std::cout<<"(0+0i)^0= "<<z2.CalculatePower(0)<<"\n";
	std::cout<<"(0+0i)^1= "<<z2.CalculatePower(1)<<"\n";
	std::cout<<"(0+0i)^2= "<<z2.CalculatePower(2)<<"\n";

	return 0;
}
