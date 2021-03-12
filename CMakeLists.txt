# Adam is currently doing a hybrid of the CMAKE tutorial, and MBolus's template
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html
# example code here: https://github.com/mbbill/CMake-Tutorial
# https://github.com/maks-it/CMake-Tutorial
#
# [x] Step 1 - something builds as long as it doesn't depend on something else
# [x] Step 2 - adding library, conditional includes
# [?] Step 3 - "usage requirements"
# [x] Step 4 - install & testing
#
#


cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# set the project name
project(hmm VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_PROJECT_NAME_CAP HMM)#all caps
set(PROJECT_URL https://github.com/stanley-rozell/hmm)

# Specify C++ standard
# n.b. this has to be before adding targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
message(STATUS "CMAKE_CXX_STANDARD = ${CMAKE_CXX_STANDARD}")

message(STATUS "prj source dir" = ${PROJECT_SOURCE_DIR})
message(STATUS "prj binary dir" = ${PROJECT_BINARY_DIR})


#glob approach from: https://github.com/NEGU93/ForbiddenDesert/blob/master/CMakeLists.txt
include_directories(
    ${PROJECT_BINARY_DIR}/include
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )


# add the executable
#add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${all_SRCS})

add_subdirectory(src)

option(USE_MYMATH "flag for using fake library" ON)
if(USE_MYMATH)
    add_subdirectory(fake_lib)
    list(APPEND EXTRA_LIBS fake_lib)
    #list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/fake_lib")
endif()

#configure_file(${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.in
#  ${PROJECT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME})
#

configure_file(${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.h.in
    ${PROJECT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME}.h)
#mbolus does this without the .h


message(STATUS "FLAG = ${USE_MYMATH}")
#
# ADD TARGETS
#

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    )

#MB includes:  ${PROJECT_BINARY_DIR}/include here

#${EXTRA_INCLUDES})

#target_include_directories(${CMAKE_PROJECT_NAME} INTERFACE
#  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
#  $<INSTALL_INTERFACE:include>)


install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/include/hmm.h" DESTINATION include)



enable_testing()

# does the application run
add_test(NAME RunTest COMMAND hmm 1)

# does the usage message work?
#add_test(NAME UsageTest COMMAND hmm)

add_test(NAME UsageTest COMMAND hmm)
set_tests_properties(UsageTest
  PROPERTIES PASS_REGULAR_EXPRESSION "UsageTest:.*number"
  )

function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
      PROPERTIES PASS_REGULAR_EXPRESSION ${result}
      )
endfunction(do_test)


#looks for this string in the answer!
set(TEST_ANS "states")

do_test(hmm 1 ${TEST_ANS})
do_test(hmm 2 ${TEST_ANS})
do_test(hmm 3 ${TEST_ANS})
do_test(hmm 4 ${TEST_ANS})
do_test(hmm 5 ${TEST_ANS})




#
