# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\SnipShot_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SnipShot_autogen.dir\\ParseCache.txt"
  "SnipShot_autogen"
  )
endif()
