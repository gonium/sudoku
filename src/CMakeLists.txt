# -*- mode: cmake; -*-
set(sudokusolve_src sudokusolve.cpp)

#include_directories(${CMAKE_SOURCE_DIR}/libflukso ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(sudokusolve ${sudokusolve_src})

# Link the executable 
target_link_libraries(sudokusolve ${GECODE_LIBRARY}
  ${GECODE_SUPPORT_LIBRARY}
  ${GECODE_SUPPORT_LIBRARY}
  ${GECODE_INT_LIBRARY}
  ${GECODE_DRIVER_LIBRARY}
  ${GECODE_MM_LIBRARY}
  ${GECODE_GIST_LIBRARY}
  ${GECODE_SEARCH_LIBRARY}
  )

# add programs to the install target - do not install the hashbench benchmark program.
INSTALL(PROGRAMS 
  ${CMAKE_CURRENT_BINARY_DIR}/sudokusolve
  DESTINATION bin)

