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

class Ceil : public Decorator
{
    public: 
        Ceil(Base* core) : Decorator(core){};
        virtual double evaluate(); 
};

class Floor : public Decorator
{
    public: 
        Floor(Base* core) : Decorator(core){};
        virtual double evaluate(); 
};

class Abs : public Decorator
{
    public: 
        Abs(Base* core) : Decorator(core){};
        virtual double evaluate(); 
};

class Trunc : public Decorator
{
    public: 
        Trunc(Base* core) : Decorator(core){};
        virtual std::string stringify(); 
};

class Paren : public Decorator
{
    public: 
        Paren(Base* core) : Decorator(core){};
        virtual std::string stringify(); 
};

#endif
