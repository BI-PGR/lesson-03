cmake_minimum_required (VERSION 3.0)

project(lesson-03)

# Find pgr-framework
string(ASCII 27 Esc)
set(RED "${Esc}[31;1m")
set(RST "${Esc}[m")

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../framework")
  message(FATAL_ERROR
  "${RED}Failed to find ../framework${RST}, fetch the repo using\n"
  "\tgit clone https://github.com/bi-pgr/framework\n"
  "next to the folder containing this project.")
endif()

add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/../framework"
  "framework"
)

# Silence deprecated GLUT functions
if(APPLE)
  add_definitions(-Wno-deprecated)
endif()

# Set up targets
add_executable(${PROJECT_NAME}
  src/asteroids.cpp
  src/render_stuff.cpp
  src/spline.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC inc/)

target_link_libraries(${PROJECT_NAME} pgr)

# Copy resources
add_custom_target(
  copy_resources
  ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/data
    ${CMAKE_CURRENT_BINARY_DIR}/data
  COMMENT "Copying Data" VERBATIM
)

add_dependencies(${PROJECT_NAME} copy_resources)
