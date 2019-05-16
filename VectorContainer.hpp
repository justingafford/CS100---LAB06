#ifndef VECTORCONTAINER_H
#define VECTORCONTAINER_H

#include "base.hpp"
#include "Sort.hpp"
#include "container.hpp"
#include <vector>
using namespace std;
class VectorContainer : public Container
{
    protected:
        Sort* sortt;
        vector<Base*> vcontainer;

    public:
        /* Constructors */
        VectorContainer() : sortt(nullptr) { };
        VectorContainer(Sort* function) : sortt(function) { };

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
