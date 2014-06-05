cmake_minimum_required (VERSION 2.8)
project (ogl)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)


#########################################################
# find freeglut
#########################################################
FIND_PATH(Freeglut_INCLUDE_DIRS GL/freeglut.h /opt/X11/include)
FIND_LIBRARY(Freeglut_LIBRARY glut.3 /opt/X11/lib)

include_directories(${Freeglut_INCLUDE_DIRS})

#link_directories(${Freeglut_LIBRARY})
link_directories("/opt/X11/lib")

IF(Freeglut_INCLUDE_DIRS)
  message("*** freeglut inlclude is found!")
ENDIF(Freeglut_INCLUDE_DIRS)

IF(Freeglut_LIBRARY)
  message("*** freeglut lib is found!")
ENDIF(Freeglut_LIBRARY)

#########################################################
# find glew
#########################################################
FIND_PATH(Glew_INCLUDE_DIRS GL/glew.h /usr/local/include)
FIND_LIBRARY(Glew_LIBRARY GLEW.1.10.0 /usr/local/lib)

include_directories(${Glew_INCLUDE_DIRS})
link_directories("/usr/local/lib")

IF(Glew_INCLUDE_DIRS)
  message("*** Glew inlclude is found!")
ENDIF(Glew_INCLUDE_DIRS)

IF(Glew_LIBRARY)
  message("*** Glew lib is found!")
ENDIF(Glew_LIBRARY)


add_definitions(-std=c++11)
ADD_EXECUTABLE (main main.cpp)


target_link_libraries(main  ${Glew_LIBRARY} ${Freeglut_LIBRARY} ${OPENGL_LIBRARIES} )