#include <math.h>
#inlcude "base.h"

class Decorator : public Base
{
    protected:
        Base* core;

    public:
        Decorator(Base* core){};
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
}

Class Ceil : public Decorator
{
    public: 
        Ceil(Base* core);
        virtual double evaluate(); 
}

Class Floor : public Decorator
{
    public: 
        Floor(Base* core);
        virtual double evaluate(); 
}

Class Abs : public Decorator
{
    public: 
        Abs(Base* core);
        virtual double evaluate(); 
}

Class Trunc : public Decorator
{
    public: 
        Trunc(Base* core);
        virtual std::string stringify(); 
}

Class Paren : public Decorator
{
    public: 
        Paren(Base* core);
        virtual std::string stringify(); 
}

