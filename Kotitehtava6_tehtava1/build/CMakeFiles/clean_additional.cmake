# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Kotitehtava6_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Kotitehtava6_autogen.dir\\ParseCache.txt"
  "Kotitehtava6_autogen"
  )
endif()
