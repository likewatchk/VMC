cmake_minimum_required(VERSION 2.8.3)
project(curb_test_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES curb_test_pkg
 CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs message_runtime
 DEPENDS system_lib
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(curb_test_node src/curb_test.cpp src/point_add.cpp)
target_link_libraries(curb_test_node ${catkin_LIBRARIES})
add_dependencies(curb_test_node biginner_gencpp)
