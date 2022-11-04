#include "Matrix2.hpp"
#include<cassert>

Matrix2::Matrix2(){
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			mat[i][j]=0.0;
		}
	}
}

Matrix2::Matrix2(double m11, double m12, double m21, double m22){
	mat[0][0] = m11;
	mat[0][1] = m12;
	mat[1][0] = m21;
	mat[1][1] = m22;
}

Matrix2::Matrix2(const Matrix2& m){
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			mat[i][j]=m.mat[i][j];
		}
	}
}

double Matrix2::calcDet(){
	return (mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]);
}


Matrix2 Matrix2::inverse(){
	double det = calcDet();
	assert(det!=0.0);
	Matrix2 inv;
	inv.mat[0][0]= (1.0/det)*mat[1][1];
	inv.mat[0][1]= -(1.0/det)*mat[0][1];
	inv.mat[1][0]= -(1.0/det)*mat[1][0];
	inv.mat[1][1]= (1.0/det)*mat[0][0];
	return inv;
}

Matrix2& Matrix2::operator=(const Matrix2& m){
	for (int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			mat[i][j] = m.mat[i][j];
		}
	}
	return *this;
}

Matrix2 Matrix2::operator-()const{
	Matrix2 m;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			m.mat[i][j] = -mat[i][j];
		}
	}
	return m;
}

Matrix2 Matrix2::operator+(const Matrix2& B)const{
	Matrix2 A;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			A.mat[i][j]=B.mat[i][j] + mat[i][j];
		}
	}
	return A;
}

Matrix2 Matrix2::operator-(const Matrix2& B)const{
	Matrix2 A;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			A.mat[i][j]=B.mat[i][j] - mat[i][j];
		}
	}
	return A;
}

Matrix2 Matrix2::scalarMult(double alpha)const{
	Matrix2 scalMat;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			scalMat.mat[i][j]=alpha*mat[i][j];
		}
	}
	return scalMat;
}

std::ostream& operator<<(std::ostream& output, const Matrix2& m){
	output<<"The 2X2 matrix looks like \n";
	for (int i=0; i<2;++i){
		if(i%2==1)
			output<<"\n";
		for(int j=0;j<2;++j){
			output<< m.mat[i][j]<<" ";
		}
	}
	output<<"\n";
	return output;
}