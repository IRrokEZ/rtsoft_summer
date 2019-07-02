cmake_minimum_required(VERSION 2.8)

project( fb0 )

find_package( OpenCV REQUIRED )
find_package( OpenGL )

if(OPENGL_FOUND)
  include_directories( ${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} )
else()
  include_directories( ${OpenCV_INCLUDE_DIRS} )
endif()


add_executable( fb0 example_02-10.cpp  )


target_link_libraries( fb0 ${OpenCV_LIBS} )



