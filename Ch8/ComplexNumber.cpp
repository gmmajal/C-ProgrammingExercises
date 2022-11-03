#include "ComplexNumber.hpp"
#include <cmath>

/*Code modified by GMMajal
 *In particular the following additions have been made 
 *1) Additional constructor
 *2) Copy constructor
 *3) Getter and setter method for private members
 *4) Method for generating complex conjugate
 *5) Method for setting a complex number to its complex conjugate
 *6) Two friend functions that get the values for private members.
 * */

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
   mRealPart = 0.0;
   mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
   mRealPart = x;
   mImaginaryPart = y;
}

//Constructor that generates a real number z=x+0i
ComplexNumber::ComplexNumber(double x){
	mRealPart=x;
	mImaginaryPart=0.0;
}

//Copy constructor for the complex number class
ComplexNumber::ComplexNumber(const ComplexNumber &z){
   mRealPart = z.mRealPart; 
	mImaginaryPart = z.mImaginaryPart;
}

// Getter method for the real part
double ComplexNumber::getRealPart()const{
	return mRealPart;
}

//Getter method for the imaginary part
double ComplexNumber::getImaginaryPart()const{
	return mImaginaryPart;
}

//Method for getting complex conjugate of a complex number
const ComplexNumber ComplexNumber::CalculateConjugate(ComplexNumber& z){
	ComplexNumber zbar(z.mRealPart,-z.mImaginaryPart);
	return zbar;
}

//Method for setting the complex number to its conjugate
void ComplexNumber::SetToConjugate(ComplexNumber& z){
	z.mImaginaryPart= - z.mImaginaryPart;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
   return sqrt(mRealPart*mRealPart+
               mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
   return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
   double modulus = CalculateModulus();
   double argument = CalculateArgument();
   double mod_of_result = pow(modulus, n);
   double arg_of_result = argument*n;
   double real_part = mod_of_result*cos(arg_of_result);
   double imag_part = mod_of_result*sin(arg_of_result);
   ComplexNumber z(real_part, imag_part); 
   return z; 
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
               operator=(const ComplexNumber& z)
{
   mRealPart = z.mRealPart;
   mImaginaryPart = z.mImaginaryPart;
   return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
   ComplexNumber w;
   w.mRealPart = -mRealPart;
   w.mImaginaryPart = -mImaginaryPart;
   return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
              operator+(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart + z.mRealPart;
   w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
   return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
              operator-(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart - z.mRealPart;
   w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
   return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, 
                         const ComplexNumber& z)
{
   // Format as "(a + bi)" or as "(a - bi)"
   output << "(" << z.mRealPart << " ";
   if (z.mImaginaryPart >= 0.0)
   {
      output << "+ " << z.mImaginaryPart << "i)";
   }
   else
   {
      // z.mImaginaryPart < 0.0
      // Replace + with minus sign 
      output << "- " << -z.mImaginaryPart << "i)";
   }
   return output;
}

//friend function to return real part of complex number
double RealPart(const ComplexNumber& z){
	return z.mRealPart;
}

//friend function to retunr imaginary part of complex number
double ImaginaryPart(const ComplexNumber &z){
	return z.mImaginaryPart;
}

//Code from Chapter06.tex line 986 save as ComplexNumber.cpp
