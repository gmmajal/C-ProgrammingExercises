#ifndef MATRIX2HEADER
#define MATRIX2HEADER

#include <iostream>

class Matrix2{
	public:
		Matrix2();
		Matrix2(double m11, double m12, double m21, double m22);
		Matrix2(const Matrix2& m);
		double calcDet();
		Matrix2 inverse();
		Matrix2& operator=(const Matrix2& m);
		Matrix2 operator-()const;
		Matrix2 operator+ (const Matrix2& b)const;
		Matrix2 operator-(const Matrix2& b)const;
		Matrix2 scalarMult(double alpha)const;
		friend std::ostream& operator<<(std::ostream& output, 
										const Matrix2& m);
	private:
		double mat[2][2];
};


#endif
