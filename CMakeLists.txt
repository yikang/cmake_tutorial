cmake_minimum_required(VERSION 2.8)
project(CMake_Tutorial)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

# set vairale:  -DCMAKE_BUILD_TYPE=XXXX to set this variable
message("build type: " ${CMAKE_BUILD_TYPE}) 

# refer to name of project(XXXX)
message("project: " ${PROJECT_NAME})

#check library
find_package(Eigen3 3.1.0 REQUIRED)
MESSAGE("Eigen3 VERSION:" ${Eigen3_VERSION})
message("EIGEN3_INCLUDE_DIR: " ${EIGEN3_INCLUDE_DIR})

message("PROJECT_SOURCE_DIR" ${PROJECT_SOURCE_DIR})

find_package(casadi REQUIRED)
MESSAGE("casadi VERSION:" ${casadi_VERSION})
MESSAGE("casadi incldue:" ${casadi_INCLUDE_DIR})



include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
${EIGEN3_INCLUDE_DIR}
)

# build shared library for other program to use 
add_library(camera SHARED src/camera.cpp)

# add executeable
add_executable(main_test src/test/main_test1.cpp)
target_link_libraries(main_test camera)

add_executable(main_test2 src/test/main_test1.cpp)
target_link_libraries(main_test2 camera)

add_executable(test_qp src/test/test_qp.cpp)
target_link_libraries(test_qp camera qpOASES) 

add_executable(test_casadi src/test/test_casadi.cpp)
target_link_libraries(test_casadi casadi) 

#install
install(TARGETS main_test
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)





