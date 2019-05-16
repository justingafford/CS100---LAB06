#ifndef DECORATOR_H
#define DECORATOR_H

#include <math.h>
#include "base.hpp"

class Decorator : public Base
{
    protected:
        Base* core;

    public:
        Decorator(Base* core){};
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

Class Ceil : public Decorator
{
    public: 
        Ceil(Base* core) : Decorator(core){};
        virtual double evaluate(); 
};

Class Floor : public Decorator
{
    public: 
        Floor(Base* core) : Decorator(core){};
        virtual double evaluate(); 
};

Class Abs : public Decorator
{
    public: 
        Abs(Base* core) : Decorator(core){};
        virtual double evaluate(); 
};

Class Trunc : public Decorator
{
    public: 
        Trunc(Base* core) : Decorator(core){};
        virtual std::string stringify(); 
};

Class Paren : public Decorator
{
    public: 
        Paren(Base* core) : Decorator(core){};
        virtual std::string stringify(); 
};

#endif
