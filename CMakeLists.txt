cmake_minimum_required(VERSION 2.8.3)
project(tutorial_opencv)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

find_package(OpenCV 3 REQUIRED COMPONENTS
		opencv_core
		opencv_highgui
		opencv_imgcodecs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

set(TARGET "color2gray")
add_executable(${TARGET} src/${TARGET}.cpp)
target_link_libraries(${TARGET} ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

