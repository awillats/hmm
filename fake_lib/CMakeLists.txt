add_library(fake_lib fake.cpp)

#preempts needing an "EXTRA_INCLUDES" line in main CML
target_include_directories(fake_lib
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS fake_lib DESTINATION lib)
install(FILES fake.h DESTINATION include)
