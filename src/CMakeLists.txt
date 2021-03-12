add_library(src hmm_vec.cpp)

target_include_directories(src
         INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

#install(TARGET src DESTINATION lib)
#install(FILES fake.h DESTINATION include)


# add shared library (default is static)
# set(LIB_SOURCES ${LIB_SOURCES})
# file(READ sourcelist.txt LIB_SOURCES)
# message(STATUS "LIB_SOURCES           = ${LIB_SOURCES}")
#
# target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${LIB_SOURCES})
#
# if(${CMAKE_PROJECT_NAME_CAP}_BUILD_STATIC)
#   target_sources(${CMAKE_PROJECT_NAME}Static PRIVATE ${LIB_SOURCES})
# endif()
