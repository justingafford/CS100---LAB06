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

string Trunc::stringify()
{
    return to_string(core->evaluate());
}

string Paren::stringify()
{
    return "(" + to_string(core) + ")";
}
