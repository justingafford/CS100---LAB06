#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "Sort.hpp"

class BubbleSort : public Sort {
    public:
        /* Constructors */
        BubbleSort () {};

        /* Pure Virtual Functions */
        void BubbleSort(Container* container);
};

#endif

