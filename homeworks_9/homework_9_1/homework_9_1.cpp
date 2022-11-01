// homework_9_1.cpp : Задача 1. Сравнения в дробях

#include <iostream>

class Fraction {
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator==(Fraction other) { return ((numerator_ * other.denominator_) == (denominator_ * other.numerator_));}
	bool operator!=(Fraction other) { return !(*this == other);}
	bool operator<(Fraction other) {
		if ((numerator_ != other.numerator_) && (denominator_ == other.denominator_)) {
			return (numerator_ < other.numerator_);
		}
		else if ((numerator_ == other.numerator_) && (denominator_ != other.denominator_)) {
			return (denominator_ > other.denominator_);
		}
		else {
			return ((numerator_ * other.denominator_) < (denominator_ * other.numerator_));
		}
	}
    bool operator>(Fraction other) { return (other < *this);}
	bool operator<=(Fraction other) { return (!(*this > other));}
	bool operator>=(Fraction other) { return (!(*this < other));}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(4, 3);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}