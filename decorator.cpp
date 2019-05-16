#inlcude "decorator.h"

virtual double Ceil::evaluate()
{
    return ceil(core->evaluate());
}

virtual double Floor::evaluate()
{
    return floor(core->evaluate());
}

virtual double Abs::evaluate()
{
    return abs(core->evaluate());
}

virtual string Trunc::stringify()
{
    return to_string(core->evaluate());
}

virtual string Paren::stringify()
{
    return to_string("(" + core + ")");
}
