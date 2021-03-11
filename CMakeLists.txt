# Adam is currently doing a hybrid of the CMAKE tutorial, and MBolus's template
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html

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


# add the executable
#add_subdirectory(src)
add_executable(hmm src/main.cpp)

#configure_file(${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.in
#  ${PROJECT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME})

configure_file(${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.h.in ${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}.h)


#
# ADD TARGETS
#

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

#target_include_directories(${CMAKE_PROJECT_NAME} INTERFACE
#  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
#  $<INSTALL_INTERFACE:include>)
