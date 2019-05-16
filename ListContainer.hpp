#ifndef LISTCONTAINER_H
#define LISTCONTAINER_H

#include "base.hpp"
#include "sort.hpp"
#include "container.hpp"
#include <list>
#include <iterator>

class ListContainer : public Container
{
    protected:
        Sort* sort;
        list<Base*> lcontainer;

    public:
        /* Constructors */
        ListContainer() : s(nullptr) { };
        ListContainer(Sort* function) : s(function) { };

        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        void add_element(Base* element);
        
        // iterate through trees and output the expressions (use stringify())
        void print();
        
        // calls on the previously set sorting-algorithm. Checks if sort_function is not
        // null, throw exception if otherwise
        void sort();

        /* Functions Needed to Sort */
        //switch tree locations
        void swap(int i, int j);
        
        // get top ptr of tree at index i
        Base* at(int i);
        
        // return container size
        int size();
};

#endif
