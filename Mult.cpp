#include "Mult.hpp"
#include <string>
using namespace std;
	Mult::Mult(Base* l1, Base* l2): L1(l1), L2(l2) {}
	double Mult::evaluate() {
		return L1 ->evaluate() * L2 ->evaluate();
	}
	string Mult::stringify() {
		return to_string(L1 ->stringify() + "*" + L2 ->stringify());
	}
