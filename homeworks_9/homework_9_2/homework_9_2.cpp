// homework_9_2.cpp : Задача 2. Остальные операции с дробями

#include <iostream>
#include <cmath>

unsigned int greatestCommonDivisor(unsigned int a, unsigned int b) {
    if (a % b == 0) return b;
	if (b % a == 0) return a;
	if (a > b) return greatestCommonDivisor(a % b, b);
	return greatestCommonDivisor(a, b % a);
	}

int checkDenominator(int value) {
		if (value == 0) throw "Знаменатель не должен быть равен 0!";
		return (value);
	}

class Fraction {
private:
	int numerator_ = 1;
	int denominator_ = 1;

public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
		checkDenominator(denominator_);
		simplify();
	}
	void setFraction(int n, int d) { numerator_ = n; denominator_ = d;}
	Fraction operator+(Fraction other) {
		return ((denominator_ == other.denominator_) ? Fraction((numerator_ + other.numerator_), denominator_) :
		Fraction((numerator_ * other.denominator_ + denominator_ * other.numerator_), (denominator_ * other.denominator_)));
	}
	Fraction operator-(Fraction other) {
		return ((denominator_ == other.denominator_) ? Fraction((numerator_ - other.numerator_), denominator_) :
			Fraction((numerator_ * other.denominator_ - denominator_ * other.numerator_), (denominator_ * other.denominator_)));
	}
	Fraction operator*(Fraction other) {
		return (Fraction((numerator_ * other.numerator_), (denominator_ * other.denominator_)));
	}
	Fraction operator/(Fraction other) {
		return (Fraction((numerator_ * other.denominator_), (denominator_ * other.numerator_)));
	}
	Fraction operator-() { return Fraction( - numerator_, denominator_);}
	Fraction operator++() {
		numerator_ += denominator_;
		checkDenominator(denominator_);
		simplify();
		return *this;
	}
	Fraction operator++(int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction operator--() {
		numerator_ -= denominator_;
		checkDenominator(denominator_);
		simplify();
		return *this;
	}
	Fraction operator--(int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	
	void simplify() {
		int gcd = greatestCommonDivisor(std::abs(numerator_), std::abs(denominator_));
		numerator_ /= gcd;
		denominator_ /= gcd;
		if (denominator_ < 0) { 
			denominator_ *= -1;
			numerator_ *= -1;
		}
	}
	
	friend std::ostream& operator<<(std::ostream&, const Fraction& value);
    
};

std::ostream& operator<<(std::ostream& ost, const Fraction& value) {
	ost << value.numerator_ << "/" << value.denominator_;
	return ost;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int valueN1, valueD1, valueN2, valueD2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> valueN1;
	while (true) {
		std::cout << "Введите знаменатель дроби 1: ";
		std::cin >> valueD1;
		try { checkDenominator(valueD1); break;}
		catch(const char* check) { std::cout << check << std::endl; continue;}
	}
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> valueN2;
	while (true) {
		std::cout << "Введите знаменатель дроби 2: ";
		std::cin >> valueD2;
		try { checkDenominator(valueD2); break;}
		catch (const char* check) {std::cout << check << std::endl; continue;}
	}
	Fraction f1(1, 1);
	Fraction f2(1, 1);
	Fraction* ptr;
	ptr = &f1; 
	ptr->setFraction(valueN1, valueD1);
	ptr = &f2;
	ptr->setFraction(valueN2, valueD2);
	Fraction sum = f1 + f2;
	Fraction sub = f1 - f2;
	Fraction mult = f1 * f2;
	Fraction div = f1 / f2;
	Fraction expression1 = ++f1 * f2;
	Fraction expression2 = f1-- * f2;
	std::cout << f1 << " + " << f2 << " = " << sum << std::endl;
	std::cout << f1 << " - " << f2 << " = " << sub << std::endl;
	std::cout << f1 << " * " << f2 << " = " << mult << std::endl;
	std::cout << f1 << " / " << f2 << " = " << div << std::endl;
	std::cout << "++" << f1 << " * " << f2 << " = " << expression1 << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;
	std::cout << f1 << "-- * " << f2 << " = " << expression2 << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;

	return 0;
}