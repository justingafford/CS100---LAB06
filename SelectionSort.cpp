#include <iostream>
#include "SelectionSort.hpp"

void SelectionSort::SelectionSort(Container* container) {
	for (unsigned i = 0; i < container->size(); i++) {
		unsigned index = i;
		for (unsigned j = i + 1; j < container -> size(); ++j) {
			if ((*container).at(j)->evaluate() < (*container).at(min)->evaluate()) {
				index = j;
			}
		}
		container->swap(i,min);
	}
}
