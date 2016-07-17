add_executable(led_driver_test_app
  led_driver_test.c led_driver_test_runner.c test.c)

target_include_directories(led_driver_test_app PUBLIC ../mocks)
target_link_libraries(led_driver_test_app led Unity mocks)

enable_testing()
add_test(led_driver_test led_driver_test_app)
