#include "decorator.h"

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

string Paren::stringify()
{
    string temp = "(" + core->stringify() + ")";
    return temp;
}
