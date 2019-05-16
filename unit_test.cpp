#include "base.hpp"
#include "Op.cpp"
#include "Rand.cpp"
#include "Mult.cpp"
#include "Div.cpp"
#include "Add.cpp"
#include "Sub.cpp"
#include "Pow.cpp"
#include "container.hpp"
#include "ListContainer.cpp"
#include "VectorContainer.cpp"
#include "Sort.hpp"
#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include "gtest/gtest.h"

TEST(VectorContainerTestSet, SwapTest) {
    	// Setup the elements under test
	Op* seven = new Op(7);
       	VectorContainer* test_container = new VectorContainer();
    
       	// Exercise some functionality of the  test elements
   	test_container->add_element(seven);
    
      	// Assert that the container has at least a single element
   	// otherwise we are likely to cause a segfault when accessing
    	ASSERT_EQ(test_container->size(), 1);
       	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}


TEST(ListContainerTestSet, SwapTest) {
 	// Setup the elements under test
       	Op* sixitynine = new Op(69);
    	ListContainer* test_container = new ListContainer();
        
  	// Exercise some functionality of the  test elements
       	test_container->add_element(sixitynine);
        
   	// Assert that the container has at least a single element
       	// otherwise we are likely to cause a segfault when accessing
      	ASSERT_EQ(test_container->size(), 1);
        EXPECT_EQ(test_container->at(0)->evaluate(), 69);
}
        
                                                                       

TEST(SortTestSet, SelectionSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Ope* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, BubbleSortTest) {
    Op* one = new Op(1);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(one, four);

    Op* zero = new Op(0);
    Op* two = new Op(2);
    Add* TreeB = new Add(zero, two);

    Op* six = new Op(6);
    Op* sixx = new Op(6);
    Sub* TreeC = new Sub(six, sixx);

    ListContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 2);
    EXPECT_EQ(container->at(2)->evaluate(), 0);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 0);
    EXPECT_EQ(container->at(1)->evaluate(), 2);
    EXPECT_EQ(container->at(2)->evaluate(), 4);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

