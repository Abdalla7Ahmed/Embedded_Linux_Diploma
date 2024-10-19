# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appText_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appText_autogen.dir/ParseCache.txt"
  "appText_autogen"
  )
endif()
