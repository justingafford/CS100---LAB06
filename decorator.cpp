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

virtual string Trunc::stringnify()
{
    return to_string(core->evaluate());
}

virtual string Paren::stringnify()
{
    return to_string("(" + core + ")");
}
