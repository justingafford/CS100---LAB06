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
    Op* op1 = new Op(-2.3);
    Op* op2 = new Op(6.9);
   
    Ceil* cop1 = new Ceil(op1);
    Ceil* cop2 = new Ceil(op2);
    VectorContainer* test_container = new VectorContainer();
    
    // Exercise some functionality of the  test elements
    test_container->add_element(cop1);
    test_container->add_element(cop2);
    ASSERT_EQ(test_container->at(0)->evaluate(),-2.0);
    ASSERT_EQ(test_container->at(1)->evaluate(),7.0);
}

TEST(DecoratorTest,FloorTest) {
    Op* op1 = new Op(-2.3);
    Op* op2 = new Op(6.9);
    
    
    Floor* cop1 = new Floor(op1);
    Floor* cop2 = new Floor(op2);
    EXPECT_EQ(cop1->evaluate(),-3.0);
    EXPECT_EQ(cop2->evaluate(),6.0);	
}

TEST(DecoratorTest,AbsTest) {
    Op* op1 = new Op(-2.3);
    Op* op2 = new Op(6.9);
    
    
    Abs* cop1 = new Abs(op1);
    Abs* cop2 = new Abs(op2);
    EXPECT_EQ(cop1->evaluate(),2.3);
    EXPECT_EQ(cop2->evaluate(),6.9);	
}

TEST(DecoratorTest,TruncTest) {
     Op* op1 = new Op(6);
     Op* op2 = new Op(9);
     Op* op3 = new Op(4);
     Sub* sub1 = new Sub(op2,op3);
     Trunc* trunc1 = new Trunc(sub1);
     Add* add1 = new Add(op1,trunc1);
     EXPECT_EQ(add1->stringify(),"6.000000+5.000000");
     EXPECT_EQ(add1->evaluate(), 1.000000);
     
}

TEST(DecoratorTest,ParenTest) {
     Op* op1 = new Op(5);
     Op* op2 = new Op(7);
     Op* op3 = new Op(4);
     Sub* sub1 = new Sub(op2,op3);
     Paren* trunc1 = new Paren(sub1);
     Add* add1 = new Add(op1,trunc1);
     EXPECT_EQ(add1->stringify(),"5.000000+(7.000000-4.000000)");
     EXPECT_EQ(add1->evaluate(), 8.000000);
}

TEST(DecoratorTest,CombinedTest) {
     Op* op1 = new Op(-4.2);
     Op* op2 = new Op(7.7);
     Abs* abs1 = new Abs(op1);
     Floor* flr1 = new Floor(op2);
     Floor* flr2 = new Floor(abs1);
     Ceil* ceil1 = new Ceil(flr1);
     EXPECT_EQ(flr2->evaluate(), 4.000000);
     EXPECT_EQ(ceil1->evaluate(), 7.000000);
    
}

TEST(ArithTest, OpNumber)  {

    Op* op1 = new Op(5.0); 
    Op* op2 = new Op(7.0); 
    Op* op3 = new Op(2.0); 

    EXPECT_EQ(op1 -> evaluate(), 5.0);
    EXPECT_EQ(op1 ->stringify(), "5.000000");

    Add* add1 = new Add(op1, op2);
    EXPECT_EQ(add1->evaluate(), 12);
    EXPECT_EQ(add1->stringify(), "5.000000+7.000000");

    Sub* sub1 = new Sub(add1 , op2);
    EXPECT_EQ(sub1->evaluate(), 5);
    EXPECT_EQ(sub1->stringify(), "5.000000+7.000000-7.000000");

    Mult* mult1 = new Mult(sub1 , op3);
    EXPECT_EQ(mult1  ->evaluate(),  10);
    EXPECT_EQ(mult1  ->stringify(), "5.000000+7.000000-7.000000*2.000000");

    Div* div1 = new Div(mult1  , op3);
    EXPECT_EQ(div1  ->evaluate(),  5);
    EXPECT_EQ(div1  ->stringify(), "5.000000+7.000000-7.000000*2.000000/2.000000");

    Pow* pow1 = new Pow(div1, op3);
    EXPECT_EQ(pow1  ->evaluate(),  25);
    EXPECT_EQ(pow1  ->stringify(), "5.000000+7.000000-7.000000*2.000000/2.000000**2.000000");
}





int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
