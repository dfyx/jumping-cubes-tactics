#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(jct_sfml)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Update source dir
set(PROJECT_ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

# Set version information in a config.h file
set(jct_sfml_VERSION_MAJOR 1)
set(jct_sfml_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "jct_sfml")
add_executable(${EXECUTABLE_NAME}
	"${PROJECT_SOURCE_DIR}/main.cpp"
	"${PROJECT_SOURCE_DIR}/gamedata/node.cpp"
	"${PROJECT_SOURCE_DIR}/gamedata/edge.cpp"
	"${PROJECT_SOURCE_DIR}/gamedata/game.cpp"
	"${PROJECT_SOURCE_DIR}/gamedata/player.cpp"
	"${PROJECT_SOURCE_DIR}/gamelogic/turncontroller.cpp"
	"${PROJECT_SOURCE_DIR}/graphics/node_sprite.cpp"
	"${PROJECT_SOURCE_DIR}/graphics/edge_sprite.cpp"
	"${PROJECT_SOURCE_DIR}/loaders/grid_game_loader.cpp"
	"${PROJECT_SOURCE_DIR}/loaders/simple_game_loader.cpp"
)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Copy maps
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND mkdir -p ${PROJECT_BINARY_DIR}/data
)
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND cp ${PROJECT_ROOT_DIR}/data/*.jct ${PROJECT_BINARY_DIR}/data
)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${jct_sfml_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${jct_sfml_VERSION_MINOR}")
include(CPack)