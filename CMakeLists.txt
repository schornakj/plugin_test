cmake_minimum_required(VERSION 3.16.3)
project(plugin_test)

find_package(ament_cmake REQUIRED)
find_package(pluginlib REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
    pluginlib
)

add_library(loader_base SHARED
  src/loader_base.cpp
  src/factory.cpp)
target_include_directories(loader_base
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PUBLIC $<INSTALL_INTERFACE:include>)
ament_target_dependencies(loader_base ${THIS_PACKAGE_INCLUDE_DEPENDS})

add_library(my_class_intermediate SHARED
  src/my_class_intermediate.cpp)
target_include_directories(my_class_intermediate
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PUBLIC $<INSTALL_INTERFACE:include>)
ament_target_dependencies(my_class_intermediate ${THIS_PACKAGE_INCLUDE_DEPENDS})

add_library(loader_derived SHARED
  src/my_class.cpp
  src/loader_derived.cpp)
target_include_directories(loader_derived
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(loader_derived loader_base my_class_intermediate)
ament_target_dependencies(loader_derived ${THIS_PACKAGE_INCLUDE_DEPENDS})

install(
  TARGETS
    loader_base
    my_class_intermediate
    loader_derived
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

pluginlib_export_plugin_description_file(${PROJECT_NAME} loader_description.xml)

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
