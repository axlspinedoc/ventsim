#-------------------------------------------------------------------------------
# @file: CMakeLists.txt
# @created on: April 18th, 2020
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5)
project(lung)
message(STATUS "Building ${PROJECT_NAME} Library")

# Specify the C++ standard
# set(PYTHON_INCLUDE_DIR=/usr/include/python2.7)
# set(PYTHON_LIBRARY=/usr/lib/python2.7/config/libpython2.7.so)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(LUNG_TEST True)


# Internal required headers 
include_directories( 
  inc
  ${BUILD_INCLUDE_OUTPUT_DIRECTORY}
  ${PYTHON_INCLUDE_DIR}
)

# Local header files
set(LUNG_HEADERS 
 	${PROJECT_SOURCE_DIR}/lung/${PROJECT_NAME}.h
)

# Local source files
set(LUNG_SOURCES 
	${PROJECT_SOURCE_DIR}/lung/${PROJECT_NAME}.cpp
)

# # Lung libraries needed
set(LUNG_LIBRARIES 
	${PYTHON_LIBRARY}
)

# Project library
add_library(${PROJECT_NAME} SHARED ${LUNG_SOURCES} ${LUNG_HEADERS})

# Link required libraries to project
target_link_libraries(${PROJECT_NAME} 
  ${LUNG_LIBRARIES}
)

if(LUNG_TEST)
  # Add tests here 
  add_executable(test_natural_respiration 
  	test/natural_respiration/test_natural_respiration.cpp)
  target_link_libraries(test_natural_respiration
    ${PROJECT_NAME} 
  )
  add_executable(test_vcv 
  	test/volume_control/test_vcv.cpp)
  target_link_libraries(test_vcv
    ${PROJECT_NAME} 
  )
endif()