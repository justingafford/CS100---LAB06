#ifndef SORT_HPP
#define SORT_HPP

#include "container.h"

class Sort {
    public:
        /* Constructors */
        Sort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

#endif
