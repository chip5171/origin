#include "rhombus.h"

Rhombus::Rhombus() {
    name = "Ромб";
    a_ = b_ = c_ = d_ = 0;
    A_ = C_ = 0;
    B_ = D_ = 0;
}
Rhombus::Rhombus(int a, int A, int B) {
    name = "Ромб";
    a_ = b_ = c_ = d_ = a;
    A_ = C_ = A;
    B_ = D_ = B;
}
	