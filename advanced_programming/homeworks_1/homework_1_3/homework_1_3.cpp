// homework_1_2.cpp : CPPL-5 Задача 3*. Операции над углами

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>

#define PI 3.14159265


int main(int argc, char** argv) {

	setlocale(LC_ALL, "Rus");
	
	std::vector<int> anglesDegrees = { 30, 60, 90 };
	
	std::vector<double> angles;
	for (int i : anglesDegrees) {
		angles.push_back(i * PI / 180);
	}

	auto f_cos = [](double a) {std::cout << "\b cos:" << cos(a); };
	auto f_sin = [](double a) {std::cout << "\b sin:" << sin(a); };

	std::vector<std::function<void(double)>> functions{f_sin, f_cos};
	
	std::cout << "[Входные данные]:";
	std::for_each(anglesDegrees.begin(), anglesDegrees.end(), [](int ang) { std::cout << ang << " * 3.1415926 / 180,";});
	std::cout << "\b // перевод из градусов в радианы" << std::endl;
	
	std::cout << "[Выходные данные]:" << std::endl;
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
	return 0;
}
