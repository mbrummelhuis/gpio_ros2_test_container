cmake_minimum_required(VERSION 3.8)
project(gpio_test_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(gpio_test_package src/gpio_test_package.cpp)
ament_target_dependencies(gpio_test_package rclcpp std_msgs)
include_directories(
  include
)

target_link_libraries(gpio_test_package
  wiringPi
)

install(TARGETS
  gpio_test_package
  DESTINATION lib/${PROJECT_NAME})

ament_package()
