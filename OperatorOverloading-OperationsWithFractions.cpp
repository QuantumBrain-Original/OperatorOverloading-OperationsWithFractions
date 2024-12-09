#include <iostream>
#include <exception>
#include <string>
#include <Windows.h>

class Fraction
{
	private:
		int numerator_;
		int denominator_;
	public:

		Fraction operator + (Fraction& num)
		{
			return Fraction(numerator_ * num.denominator_ + num.numerator_ * denominator_, denominator_ * num.denominator_);
		}

		Fraction operator - (Fraction& num)
		{
			return Fraction(numerator_ * num.denominator_ - num.numerator_ * denominator_, denominator_ * num.denominator_);
		}

		Fraction operator * (Fraction& num)
		{
			return Fraction(numerator_ * num.numerator_, denominator_ * num.denominator_);
		}

		Fraction operator / (Fraction& num)
		{
			return Fraction(numerator_ * num.denominator_, denominator_ * num.numerator_);
		}

		Fraction& operator -()
		{
			numerator_ = -numerator_;
			denominator_ = -denominator_;
			return (*this);
//			return Fraction(-numerator_, denominator_);
		}

		Fraction& operator++()
		{
			numerator_ += 1;
//			denominator_ += 1;
			return (*this);
		}

		Fraction operator++(int)
		{
			Fraction tmp = *this;
			++(*this);
			return tmp;
		}

		Fraction& operator--()
		{
			numerator_ -= 1;
//			denominator_ -= 1;
			return (*this);
		}

		Fraction operator--(int)
		{
			Fraction tmp = *this;
			--(*this);
			return tmp;
		}

		std::string output_result()
		{
//			int tmp1, tmp2;
//			tmp1 = numerator_;
//			tmp2 = denominator_;
			for(int i = 9; i > 1; i--)
			{
				while (numerator_ % i == 0 && denominator_ % i == 0)
				{
					numerator_ /= i;
					denominator_ /= i;
				}
			}
			return std::to_string(numerator_) + "/" + std::to_string(denominator_);
		}

		Fraction(int numerator, int denominator)
		{
			numerator_ = numerator;
			denominator_ = denominator;
		}
};

int main() // Задача 2. Остальные операции с дробями
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int a = 1, b = 1, x = 1, z = 1;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> b;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> x;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> z;

	Fraction f1(a, b);
	Fraction f2(x, z);

	std::cout << a << "/" << b << " + " << x << "/" << z << " = " << (f1 + f2).output_result() << '\n';
	std::cout << a << "/" << b << " - " << x << "/" << z << " = " << (f1 - f2).output_result() << '\n';
	std::cout << a << "/" << b << " * " << x << "/" << z << " = " << (f1 * f2).output_result() << '\n';
	std::cout << a << "/" << b << " / " << x << "/" << z << " = " << (f1 / f2).output_result() << '\n';
//	std::cout << -a << "/" << b << " = " << (-f1).output_result() << '\n';
//	Fraction f12 = f1 * f2;
	std::cout << "++" << a << "/" << b << " * " << x << "/" << z << " = " << ((++f1) * f2).output_result() << '\n';
	std::cout << a << "/" << b << "--" << " * " << x << "/" << z << " = " << ((f1--) * f2).output_result() << '\n';
	std::cout << a << "/" << b << "++" << " * " << x << "/" << z << " = " << ((f1++) * f2).output_result() << '\n';
	std::cout << "--" << a << "/" << b << " * " << x << "/" << z << " = " << ((--f1)*f2).output_result() << '\n';
	std::cout << "-" << a << "/" << b << " * " << x << "/" << z << " = " << (-f1 * f2).output_result() << '\n';
	return 0;
}