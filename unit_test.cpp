#include "base.hpp"
#include "Op.hpp"
#include "Rand.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "container.hpp"
#include "ListContainer.hpp"
#include "VectorContainer.hpp"
#include "SelectionSort.hpp"
#include "Sort.hpp"
#include "BubbleSort.hpp"
#include "decorator.h"
#include "gtest/gtest.h"
#include<iostream>
using namespace std;

TEST(DecoratorTest,CeilTest) {
	
}

TEST(DecoratorTest,FloorTest) {
	
}

TEST(DecoratorTest,AbsTest) {
	
}

TEST(DecoratorTest,TruncTest) {
	
}

TEST(DecoratorTest,ParenTest) {
	
}

TEST(VectorContainerTestSet, SwapTest) {
    	// Setup the elements under test
	Op* seven = new Op(7);
	Op* two = new Op(2);
       	VectorContainer* test_container = new VectorContainer();
    
       	// Exercise some functionality of the  test elements
   	test_container->add_element(seven);
	test_container->add_element(two);
    
      	// Assert that the container has at least a single element
   	// otherwise we are likely to cause a segfault when accessing
    	ASSERT_EQ(test_container->size(), 2);
       	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
	EXPECT_EQ(test_container->at(1)->evaluate(), 2);
	
	test_container->swap(0, 1);
	EXPECT_EQ(test_container->at(1)->evaluate(), 7);
	EXPECT_EQ(test_container->at(0)->evaluate(), 2);
}

TEST(SortTestSet, VSelectionSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
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

TEST(SortTestSet, VBubbleSortTest) {
    Op* one = new Op(1);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(one, four);

    Op* zero = new Op(0);
    Op* two = new Op(2);
    Add* TreeB = new Add(zero, two);

    Op* six = new Op(6);
    Op* sixx = new Op(6);
    Sub* TreeC = new Sub(six, sixx);

    VectorContainer* container = new VectorContainer();
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

TEST(ListContainerTestSet, PrintTest) {
 	// Setup the elements under test
	Op* seven = new Op(7);
       	ListContainer* test_container = new ListContainer();
    
       	// Exercise some functionality of the  test elements
   	test_container->add_element(seven);
    
      	// Assert that the container has at least a single element
   	// otherwise we are likely to cause a segfault when accessing
    	cout << "start" << endl;
	ASSERT_EQ(test_container->size(), 1);
       	cout << "end" << endl;
	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
	
	test_container->print();
} 
   
TEST(ListContainerTestSet, SwapTest) {
 	// Setup the elements under test
	Op* seven = new Op(7);
	Op* two = new Op(2);
       	ListContainer* test_container = new ListContainer();
    
       	// Exercise some functionality of the  test elements
   	test_container->add_element(seven);
	test_container->add_element(two);
    
      	// Assert that the container has at least a single element
   	// otherwise we are likely to cause a segfault when accessing
    	ASSERT_EQ(test_container->size(), 2);
       	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
	EXPECT_EQ(test_container->at(1)->evaluate(), 2);
	
	test_container->swap(0, 1);
	EXPECT_EQ(test_container->at(1)->evaluate(), 7);
	EXPECT_EQ(test_container->at(0)->evaluate(), 2);
}
        
TEST(VectorContainerTestSet, PrintTest) {
 	// Setup the elements under test
	Op* seven = new Op(7);
       	VectorContainer* test_container = new VectorContainer();
    
       	// Exercise some functionality of the  test elements
   	test_container->add_element(seven);
    
      	// Assert that the container has at least a single element
   	// otherwise we are likely to cause a segfault when accessing
    	ASSERT_EQ(test_container->size(), 1);
       	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
	
	test_container->print();
}        
                                        

TEST(SortTestSet, LBubbleSortTest) {
    Op* one = new Op(1);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(one, four);

    Op* zero = new Op(0);
    Op* two = new Op(2);
    Add* TreeB = new Add(zero, two);

    Op* six = new Op(6);
    Op* sixx = new Op(6);
    Sub* TreeC = new Sub(six, sixx);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    cout<<"\nInside LBubblesort before size check";
    ASSERT_EQ(container->size(), 3);
    cout<<"\nInside LBubblesort AFTER size check";
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 2);
    EXPECT_EQ(container->at(2)->evaluate(), 0);
    cout << "oof" << endl;
    container->set_sort_function(new BubbleSort());
    cout << "0" << endl;
    container->sort();
    cout << "1" << endl;
    ASSERT_EQ(container->size(), 3);
    cout << "2" << endl;
    EXPECT_EQ(container->at(0)->evaluate(), 0);
    cout << "3" << endl;
    EXPECT_EQ(container->at(1)->evaluate(), 2);
    cout << "4" << endl;
    EXPECT_EQ(container->at(2)->evaluate(), 4);
}

TEST(SortTestSet, LSelectionSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    //cout<<"\nInside LSelectionsort before adding elements";
    container->add_element(TreeA);
    //cout<<"\n1--------Inside LSelectionsort before adding elements";
    container->add_element(TreeB);
    //cout<<"\n2------------Inside LSelectionsort before adding elements";
    container->add_element(TreeC);

    //cout<<"\nInside LSelectionsort before size check";
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



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
