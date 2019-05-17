#include "decorator.h"
#include <iostream>
double Ceil::evaluate()
{
    return ceil(core->evaluate());
}

double Floor::evaluate()
{
    return floor(core->evaluate());
}

double Abs::evaluate()
{
    return abs(core->evaluate());
}

double Trunc::evaluate()
{
    return core->evaluate();
}

double Paren::evaluate()
{
    string temp = "(" + core->evaluate() + ")";
    double par = static_cast<double>temp;
    return par;
}
