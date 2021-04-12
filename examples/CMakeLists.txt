# add executables
add_executable(eg_hmm main.cpp)
target_link_libraries(eg_hmm PUBLIC ${CMAKE_PROJECT_NAME} ${PROJECT_LIBS})
