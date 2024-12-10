#include <iostream>
#include <exception>
#include <numeric>
#include <Windows.h>

#define cPRINTs std::cout <<
#define cPRINTe << '\n'
#define cINPUT std::cin >>

class Fraction
{
		int numerator_;
		int denominator_;
	public:

		Fraction operator + (Fraction& num) const
		{
			return Fraction(numerator_ * num.denominator_ + num.numerator_ * denominator_, denominator_ * num.denominator_);
		}

		Fraction operator - (Fraction& num) const
		{
			return Fraction(numerator_ * num.denominator_ - num.numerator_ * denominator_, denominator_ * num.denominator_);
		}

		Fraction operator * (Fraction& num) const
		{
			return Fraction(numerator_ * num.numerator_, denominator_ * num.denominator_);
		}

		Fraction operator / (Fraction& num) const
		{
			return Fraction(numerator_ * num.denominator_, denominator_ * num.numerator_);
		}

		Fraction& operator -()
		{
			numerator_ = -numerator_;
//			denominator_ = -denominator_;
			return (*this);
		}

		Fraction operator++()
		{
			numerator_ += denominator_;
//			denominator_ += 1;
			return (*this);
		}

		Fraction operator++(int)
		{
			Fraction tmp = *this;
			++(*this);
			return tmp;
		}

		Fraction operator--()
		{
			numerator_ -= denominator_;
//			denominator_ -= 1;
			return (*this);
		}

		Fraction operator--(int)
		{
			Fraction tmp = *this;
			--(*this);
			return tmp;
		}

		friend std::ostream& operator<<(std::ostream& stream, const Fraction& num)
		{
			stream << num.numerator_ << '/' << num.denominator_;
			return stream;
		}

		Fraction(int numerator, int denominator)
		{
			if (denominator == 0)
				throw std::exception("Ошибка! Попытка деления на 0");

			int gcd = std::gcd(std::abs(numerator), std::abs(denominator));

			numerator_ = (numerator / gcd);
			denominator_ = (denominator / gcd);
		}
};

int main() // Задача 2. Остальные операции с дробями
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int a = 3, b = 4, x = 4, z = 5;
	cPRINTs "Введите числитель дроби 1: ";
	cINPUT a;
	cPRINTs "Введите знаменатель дроби 1: ";
	cINPUT b;
	cPRINTs "Введите числитель дроби 2: ";
	cINPUT x;
	cPRINTs "Введите знаменатель дроби 2: ";
	cINPUT z;

	try
	{
		Fraction f1(a, b);
		Fraction f2(x, z);

		cPRINTs f1 << " + " << f2 << " = " << (f1 + f2) cPRINTe;
		cPRINTs f1 << " - " << f2 << " = " << (f1 - f2) cPRINTe;
		cPRINTs f1 << " * " << f2 << " = " << (f1 * f2) cPRINTe;
		cPRINTs f1 << " / " << f2 << " = " << (f1 / f2) cPRINTe;

		cPRINTs "++" << f1 << " * " << f2 << " = " << (++f1 * f2) cPRINTe;
		cPRINTs "Значение переменной 1: " << f1 cPRINTe;

		cPRINTs f1 << "--" << " * " << f2 << " = " << (f1-- * f2) cPRINTe;
		cPRINTs "Значение переменной 1: " << f1 cPRINTe;

		cPRINTs f1 << "++" << " * " << f2 << " = " << (f1++ * f2) cPRINTe;
		cPRINTs "Значение переменной 1: " << f1 cPRINTe;

		cPRINTs "--" << f1 << " * " << f2 << " = " << (--f1 * f2) cPRINTe;
		cPRINTs "Значение переменной 1: " << f1 cPRINTe;

		cPRINTs "-" << f1 << " * " << f2 << " = " << (-f1 * f2) cPRINTe;
	}
	catch (const std::exception& zero_div)
	{
		cPRINTs zero_div.what() cPRINTe;
	}

	return 0;
}