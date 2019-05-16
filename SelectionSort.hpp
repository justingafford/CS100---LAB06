#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "Sort.hpp"

class SelectionSort : public Sort {
    public:
        /* Constructors */
        SelectionSort {};

        /* Pure Virtual Functions */
        void SelectionSort(Container* container);
};

#endif
