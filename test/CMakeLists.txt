find_package(ament_cmake_gtest REQUIRED)

ament_add_gtest(test_loader_plugin
  test_loader_plugin.cpp)
target_link_libraries(test_loader_plugin loader_base)
