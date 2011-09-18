# -*- mode: cmake; -*-

#set(hdrs 
#  common.hpp
#)
#install(FILES ${hdrs} DESTINATION include/sudoku)

#configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB all_sudoku_src *.cpp *.hpp)
set(sudoku_src ${all_sudoku_src})
ADD_LIBRARY(sudoku ${sudoku_src})

target_link_libraries(sudoku)

if(BUILD_SHARED_LIBS)
  install(TARGETS sudoku LIBRARY DESTINATION lib)
else(BUILD_SHARED_LIBS)
  install(TARGETS sudoku ARCHIVE DESTINATION lib)
endif(BUILD_SHARED_LIBS)

