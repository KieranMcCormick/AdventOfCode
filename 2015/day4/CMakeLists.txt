# add the executable
add_executable(day4 day4.cxx)
add_library(md5 md5.cpp)
target_link_libraries(day4 md5)