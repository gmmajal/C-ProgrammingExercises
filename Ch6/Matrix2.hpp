#ifndef MATRIX2HEADER
#define MATRIX2HEADER

#include <iostream>

class Matrix2{
	public:
		Matrix2();
		Matrix2(double m11, double m12, double m21, double m22);
		Matrix2(const Matrix2& m);
		double calcDet();
		double getElem11()const;
		double getElem12()const;
		double getElem21()const;
		double getElem22()const;
		void setElem11(double val);
		void setElem12(double val);
		void setElem21(double val);
		void setElem22(double val);
		Matrix2 inverse();
		Matrix2& operator=(const Matrix2& m);
		Matrix2 operator-()const;
		Matrix2 operator+ (const Matrix2& b)const;
		Matrix2 operator-(const Matrix2& b)const;
		Matrix2 scalarMult(double alpha)const;

	private:
		double a11;
		double a12;
		double a21;
		double a22;
};


#endif
