// Student ID: 20382528
// Quest: The Complex Kiwi
// Trophies: 19/19

#include "Complex.h"

#include <iostream> // ostream
#include <string> // string

using namespace std;

string Complex::to_string() const
{
    char* buf = new char[50];
    sprintf(buf, "(%.11g,%.11g)", _real, _imag);
    return string(buf);
}

Complex Complex::reciprocal() const
{
    double my_denominator = norm_squared();

    if (my_denominator <= Complex::FLOOR)
    {
        throw Div_By_Zero_Exception();
    }

    return Complex(_real / my_denominator, -1 * _imag / my_denominator);
}

Complex& Complex::operator=(const Complex& rhs)
{
    _real = rhs._real;
    _imag = rhs._imag;
    return *this;
}

string Complex::Div_By_Zero_Exception::to_string()
{
    return "Divide by zero exception";
}

string Complex::Div_By_Zero_Exception::what()
{
    return to_string();
}

Complex Complex::operator+(const Complex& that) const
{
    return Complex(this->_real + that._real, this->_imag + that._imag);
}

Complex Complex::operator-(const Complex& that) const
{
    return Complex(this->_real - that._real, this->_imag - that._imag);
}

Complex Complex::operator*(const Complex& that) const
{
    return Complex(this->_real * that._real - this->_imag * that._imag,
        this->_real * that._imag + this->_imag * that._real);
}

Complex Complex::operator/(const Complex& that) const
{
    return *this * that.reciprocal();
}

bool Complex::operator==(const Complex& that) const
{
    bool result = true;

    if (_real != that._real)
    {
        result = false;
    }
    if (_imag != that._imag)
    {
        result = false;
    }

    return result;
}

bool Complex::operator<(const Complex& that) const
{
    return this->norm() < that.norm();
}

ostream& operator<<(ostream& os, const Complex& x)
{
    os << x.to_string();
    return os;
}
