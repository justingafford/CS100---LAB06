#ifndef DECORATOR_H
#define DECORATOR_H

#include <math.h>
#include <string>
#include "base.hpp"

using namespace std;


class Ceil : public Base
{
    protected:
        Base* core;
    public: 
        Ceil(Base* cory) : core(cory){};
        double evaluate();
};

class Floor : public Base
{
    protected:
        Base* core;
    public: 
        Floor(Base* cory) : core(cory){};
        double evaluate();
};

class Abs : public Base
{
    protected:
        Base* core;
    public: 
        Abs(Base* cory) : core(cory){};
        double evaluate();
};

class Trunc : public Decorator
{
    protected:
        Base* core;
    public: 
        Trunc(Base* cory) : core(cory){};
        string stringify(); 
};

class Paren : public Decorator
{
    protected:
        Base* core;
    public: 
        Paren(Base* cory) : core(cory){};
        string stringify(); 
};

#endif
