#ifndef DECORATOR_H
#define DECORATOR_H

#include <math.h>
#include <string>
#include "base.hpp"

using namespace std;

class Decorator : public Base
{
    protected:
        Base* core;

    public:
        Decorator(Base* core){};
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
};

class Ceil : public Decorator
{
    public: 
        Ceil(Base* core) : Decorator(core){};
        double evaluate();
        string stringify() {};
};

class Floor : public Decorator
{
    public: 
        Floor(Base* core) : Decorator(core){};
        double evaluate();
        string stringify() {};
};

class Abs : public Decorator
{
    public: 
        Abs(Base* core) : Decorator(core){};
        double evaluate();
        string stringify() {};
};

class Trunc : public Decorator
{
    public: 
        Trunc(Base* core) : Decorator(core){};
        double evaluate() {};
        string stringify(); 
};

class Paren : public Decorator
{
    public: 
        Paren(Base* core) : Decorator(core){};
        double evaluate() {};
        string stringify(); 
};

#endif
