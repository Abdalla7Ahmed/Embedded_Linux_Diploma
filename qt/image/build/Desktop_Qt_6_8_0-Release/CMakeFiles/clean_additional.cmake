# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/appimage_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appimage_autogen.dir/ParseCache.txt"
  "appimage_autogen"
  )
endif()
