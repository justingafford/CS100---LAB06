CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest) 
 
ADD_EXECUTABLE(main
    main.cpp
)
 
ADD_EXECUTABLE(test
   unit_test.cpp
   Add.cpp
   BubbleSort.cpp
   Div.cpp
   ListContainer.cpp
   Mult.cpp
   Op.cpp
   Pow.cpp
   Rand.cpp
   SelectionSort.cpp
   Sub.cpp
   VectorContainer.cpp
   decorator.cpp
)
 
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
