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
        string stringify() {};
};

class Floor : public Base
{
    protected:
        Base* core;
    public: 
        Floor(Base* cory) : core(cory){};
        double evaluate();
        string stringify() {};
};

class Abs : public Base
{
    protected:
        Base* core;
    public: 
        Abs(Base* cory) : core(cory){};
        double evaluate();
        string stringify() {};
};

class Trunc : public Base
{
    protected:
        Base* core;
    public: 
        Trunc(Base* cory) : core(cory){};
        string stringify() {};
        double evaluate();
};

class Paren : public Base
{
    protected:
        Base* core;
    public: 
        Paren(Base* cory) : core(cory){};
        string stringify();
        double evaluate() {};
};

#endif
