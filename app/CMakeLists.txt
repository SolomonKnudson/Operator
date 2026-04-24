add_executable(inserter-test
  "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
)

target_link_libraries(inserter-test PRIVATE
  Inserter
)

