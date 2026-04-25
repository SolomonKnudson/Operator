add_executable(operator-test
  "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
)

target_link_libraries(operator-test PRIVATE
  Operator
)

