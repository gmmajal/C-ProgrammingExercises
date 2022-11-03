#include "Matrix2.hpp"
#include<cassert>

Matrix2::Matrix2(){
	a11=0.0;
	a12=0.0;
	a21=0.0;
	a22=0.0;
}

Matrix2::Matrix2(double m11, double m12, double m21, double m22){
	a11 = m11;
	a12 = m12;
	a21 = m21;
	a22 = m22;
}

Matrix2::Matrix2(const Matrix2& m){
	a11 = m.a11;
	a12 = m.a12;
	a21 = m.a21;
	a22 = m.a22;
}

double Matrix2::calcDet(){
	return (a11*a22) - (a12*a21);
}

double Matrix2::getElem11()const{
	return a11;
}

double Matrix2::getElem12()const{
	return a12;
}

double Matrix2::getElem21()const{
	return a21;
}

double Matrix2::getElem22()const{
	return a22;
}

void Matrix2::setElem11(double val){
	a11 = val;
}

void Matrix2::setElem12(double val){
	a12 = val;
}

void Matrix2::setElem21(double val){
	a21 = val;
}

void Matrix2::setElem22(double val){
	a22 = val;
}

Matrix2 Matrix2::inverse(){
	double det = calcDet();
	assert(det!=0.0);
	Matrix2 inv;
	inv.a11 = (1.0/det)*a22;
	inv.a12 = -(1.0/det)*a12;
	inv.a21 = -(1.0/det)*a21;
	inv.a22 = (1.0/det)*a11;
	return inv;
}

Matrix2& Matrix2::operator=(const Matrix2& m){
	a11 = m.a11;
	a12 = m.a12;
	a21 = m.a21;
	a22 = m.a22;
	return *this;
}

Matrix2 Matrix2::operator-()const{
	Matrix2 m;
	m.a11 = -a11;
	m.a12 = -a12;
	m.a21 = -a21;
	m.a22 = -a22;
	return m;
}

Matrix2 Matrix2::operator+(const Matrix2& B)const{
	Matrix2 A;
	A.a11 = B.a11 + a11;
	A.a12 = B.a12 + a12;
	A.a21 = B.a21 + a21;
	A.a22 = B.a22 + a22;
	return A;
}

Matrix2 Matrix2::operator-(const Matrix2& B)const{
	Matrix2 A;
	A.a11 = B.a11 - a11;
	A.a12 = B.a12 - a12;
	A.a21 = B.a21 - a21;
	A.a22 = B.a22 - a22;
	return A;
}

Matrix2 Matrix2::scalarMult(double alpha)const{
	Matrix2 scalMat;
	scalMat.a11 = a11*alpha;
	scalMat.a12 = a12*alpha;
	scalMat.a21 = a21*alpha;
	scalMat.a22 = a22*alpha;
	return scalMat;
}