#pragma once

class ostream;
class Complex;


class Complex
{
public:
	Complex(double r = 0, double i = 0) : re(r), im(i) {}
	Complex& operator += (const Complex&);
	Complex& operator + (const Complex&);
	Complex& operator - (const Complex&);
	inline double real() const { return re; }
	inline double imag() const { return im; }


private:
	double re, im;
	friend Complex& __doapl(Complex*, const Complex&);
};

// ��һ�����ᱻ�ı䣬�ڶ���������ı�
// do assignment plus
inline Complex&
__doapl(Complex *ths, const Complex &rhs) {
	ths->re += rhs.re;
	ths->im += rhs.im;
	return *ths;
}


inline Complex&
Complex::operator += (const Complex &rhs) { 
	// ���������Զ�����һ��thisָ�벢��Ϊ����������������˳�򲻶� 
	return __doapl(this, rhs);
}

inline Complex&
Complex::operator + (const Complex& rhs) {
	this->re += rhs.re;
	this->im += rhs.im;
}

inline Complex&
Complex::operator - (const Complex &rhs) {
	this->re -= rhs.re;
	this->im -= rhs.im;
}

// �ǳ�Ա�����Ĳ���������(��Ա�������ǳ�Ա����ֻ��д����һ��)

// ��ʱ����Accessor
inline double real(const Complex &x) {
	return x.real();
}

inline double imag(const Complex &x) {
	return x.imag();
}

// �ӷ�
inline Complex
operator + (const Complex &lhs, const Complex &rhs) {
	return Complex(real(lhs) + real(rhs),
				   imag(lhs) + imag(rhs));
}

inline Complex
operator + (const Complex &lhs, double rhs) {
	return Complex(real(lhs) - real(rhs), imag(lhs));
}

inline Complex
operator + (double lhs, const Complex &rhs) {
	return Complex(lhs + real(rhs), imag(rhs));
}


// ������
inline Complex
operator + (const Complex &x) {
	return x;
}

inline Complex
operator - (const Complex &x) {
	return Complex(-real(x), -imag(x));
}

// ==
inline bool
operator == (const Complex &lhs, const Complex &rhs) {
	return real(lhs) == real(rhs) && imag(lhs) == imag(rhs);
}

inline bool 
operator == (const Complex &lhs,  double rhs) {
	return real(lhs) == rhs && imag(lhs) == 0;
}

inline bool
operator == (double lhs, const Complex &rhs) {
	return lhs == real(rhs) && imag(rhs) == 0;
}

