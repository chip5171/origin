// homework_2_1.cpp : CPPL-5 Задача 1. Программа с ошибками

#include <iostream>

struct Point {
private:
	double m_x;
	double m_y;
public:
	Point(double x, double y) {
		m_x = x;
		m_y = y;
	}
	void print_point(const Point& point_object) {
		std::cout << "x:" << point_object.m_x << ", y: "
			<< point_object.m_y << std::endl;
	}
};

int main(int argc, char** argv) {

	for (int i = 0; i < 5; i++) {
		Point my_point(i, 2 * i);
		my_point.print_point(my_point);
	}
	return 0;
}

