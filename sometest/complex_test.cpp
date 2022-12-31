#include <iostream>
using namespace std;

class complex
{
public:
	complex(double r = 0, double i = 0) : re(r), im(i) { }
	double real() const { return re; }
	double imag() const { return im; }
private:
	double re, im;

};

inline double
imag(const complex& x)
{
	return x.imag();
}

inline double
real(const complex& x)
{
	return x.real();
}

inline complex
operator + (const complex& x, const complex& y)
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator + (const complex& x, double y)
{
	return complex(real(x) + y, imag(x));
}

inline complex
operator + (double x, const complex& y)
{
	return complex(x + real(y), imag(y));
}

inline complex
operator - (const complex& x, const complex& y)
{
	return complex(real(x) - real(y), imag(x) - imag(y));
}

inline complex
operator - (const complex& x, double y)
{
	return complex(real(x) - y, imag(x));
}

inline complex
operator - (double x, const complex& y)
{
	return complex(x - real(y), -imag(y));
}

inline complex
operator * (const complex& x, const complex& y)
{
	return complex(real(x) * real(y) - imag(x) * imag(y),
		real(x) * imag(y) + imag(x) * real(y));
}

inline complex
operator * (const complex& x, double y)
{
	return complex(real(x) * y, imag(x) * y);
}

inline complex
operator * (double x, const complex& y)
{
	return complex(x * real(y), x * imag(y));
}

complex
operator / (const complex& x, double y)
{
	return complex(real(x) / y, imag(x) / y);
}

complex
operator / (double x, const complex& y)
{

	double iTmp = real(y)*real(y) + imag(y)*imag(y);
	return complex((real(x)*real(y)) / iTmp, -(real(x)*imag(y)) / iTmp);
}

inline complex
operator / (const complex& x, const complex& y)
{

	double iTmp = real(y)*real(y) + imag(y)*imag(y);
	int iReal = real(x)*real(y) + imag(x)*imag(y);
	int iImag = imag(x)*real(y) - real(x)*imag(y);
	return complex(iReal / iTmp, iImag / iTmp);
}

ostream&
operator << (ostream& os, const complex& x)
{
  return os << '(' << real (x) << ',' << imag (x) << ')';
}

int main1()
{
  complex c1(2, 1);
  //complex c2(4, 0);
  complex c2(0, 0);

  //cout << c1 << endl;
  //cout << c2 << endl;
  
  cout << c1+c2 << endl;
  cout << c1-c2 << endl;
  cout << c1*c2 << endl;
  cout << c1 / c2 << endl;

  
  return 0;
}
