add_executable(hmm_unit_tests
  test_main.cpp
  test_hmm_viterbi.cpp
)

target_include_directories(hmm_unit_tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/doctest
)

target_link_libraries(hmm_unit_tests PUBLIC
  ${CMAKE_PROJECT_NAME}
)

if(NOT MSVC)
  target_compile_options(hmm_unit_tests PRIVATE -Wvla)
endif()

add_test(NAME unit_hmm_viterbi
         COMMAND hmm_unit_tests --no-intro=true)
set_tests_properties(unit_hmm_viterbi PROPERTIES TIMEOUT 30)
