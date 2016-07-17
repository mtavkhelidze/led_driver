add_library(mocks STATIC runtime_error_mock.c)
target_include_directories(mocks PUBLIC ${CMAKE_CURRENT_LIST_DIR})
