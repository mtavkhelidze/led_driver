add_executable(led_driver_test_app
  led_driver_test.c led_driver_test_runner.c test.c)
target_link_libraries(led_driver_test_app led Unity)

enable_testing()
add_test(led_driver_test led_driver_test_app)
