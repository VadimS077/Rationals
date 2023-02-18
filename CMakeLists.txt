
cmake_minimum_required (VERSION 3.8)

project ("Rationals")

set_property(GLOBAL PROPERTY USE_FOLDERS ON) 
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake") 
 
include_directories(.) 
add_subdirectory ("Rational")
 
 
add_executable(tester "tester.cpp") 
set_property(TARGET tester PROPERTY CXX_STANDARD 20) 
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT tester) 
target_link_libraries(tester Rational)



