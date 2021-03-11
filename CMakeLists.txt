# Adam is currently doing a hybrid of the CMAKE tutorial, and MBolus's template
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html
# example code here: https://github.com/mbbill/CMake-Tutorial
#
# [x] Step 1 - something builds as long as it doesn't depend on something else
# [ ] Step 2 - adding library, conditional includes
#
#
#
#
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




#add_subdirectory(src)



# add the executable
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

option(USE_MYMATH "flag for using fake library" ON)
if(USE_MYMATH)
    add_subdirectory(fake_lib)
    list(APPEND EXTRA_LIBS fake_lib)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/fake_lib")
endif()

#configure_file(${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.in
#  ${PROJECT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME})
configure_file(${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.h.in ${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.h)

#set(USE_MYMATH ON)


message(STATUS "FLAG = ${USE_MYMATH}")
#
# ADD TARGETS
#

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
 ${PROJECT_SOURCE_DIR}/include
 ${EXTRA_INCLUDES})

 message(STATUS "FLAG = ${USE_MYMATH}")

#target_include_directories(${CMAKE_PROJECT_NAME} INTERFACE
#  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
#  $<INSTALL_INTERFACE:include>)
