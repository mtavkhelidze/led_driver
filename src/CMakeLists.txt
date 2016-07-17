add_library(led STATIC led_driver.c)
target_include_directories(led PUBLIC ${CMAKE_CURRENT_LIST_DIR} ../mocks)
