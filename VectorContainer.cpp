#include "VectorContainer.hpp"

/* Pure Virtual Functions */
// push the top pointer of the tree into container
 void add_element(Base* element)
 {
  vcontainer.push_back(element);
 }
        
// iterate through trees and output the expressions (use stringify())
void print()
{
    for(int i=0; i<vcontainer.size(); i++)
    {
      vcontainer.at(i)->stringify();
    }
}
        
// calls on the previously set sorting-algorithm. Checks if sort_function is not
// null, throw exception if otherwise
void sort()
{
    if(sort_function != NULL)
    {
        //calls on the previously set sorting-algorithm
        sort_function->sort(this);
    }
    else
    {
        //throw exception
      
    }
}

/* Functions Needed to Sort */
//switch tree locations
 void swap(int i, int j)
 {
    Base* temp = vcontainer.at(i);
    vcontainer.at(i) = vcontainer.at(j);
    vcontainer.at(j) = temp;
 }
        
// get top ptr of tree at index i
Base* at(int i)
{
    return vcontainer.at(i);
}
        
// return container size
int size()
{
    return vcontainer.size();
}
