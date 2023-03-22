#include <cmath>
class Complex
{
public:
	double Re, Im;
	Complex(double re, double im) : Re(re), Im(im) {}
	Complex(double re) : Re(re), Im(0) {}
	Complex() : Re(0), Im(0) {}

	/*void show(std::ostream& o) const
	{
		o << '(' << Re << ", " << Im << ')';
	}*/
	Complex operator +(const Complex& c) const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}
	Complex operator -(const Complex& c) const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}
	Complex operator *(const Complex& c) const
	{
		return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);
	}
	Complex operator /(const Complex& c) const
	{
		return Complex((Re * c.Re + Im * c.Im) / (c.Re * c.Re + c.Im * c.Im), (-Re * c.Im + c.Re * Im)/(c.Re * c.Re + c.Im * c.Im));
	}
	Complex Conjugate(const Complex& c)
	{
		return Complex(Re, -Im);
	}
	double Mod(const Complex& c)
	{
		return sqrt(Re * Re + Im * Im);
	}
	int Arg(const Complex& c)
	{
		if (fabs(Mod(c)) == 0) return 0;
		if (c.Re > 0) return atan(c.Im / c.Re);
		if (c.Re < 0)
		{
			if (c.Im >= 0) return acos(-1) + atan(c.Im / c.Re);
			return  -acos(-1) - atan(c.Im / c.Re);
		}
		if (c.Im > 0) return acos(0);
		return -acos(0);
	}
};
inline std::ostream& operator << (std::ostream& o, const Complex& c)
{
	if (c.Im > 0) return o << c.Re << "+" << c.Im << 'i';
	if (c.Im < 0) return o << c.Re << "" << c.Im << 'i';
	return o << c.Re;
}
