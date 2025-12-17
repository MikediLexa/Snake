cmake_minimum_required(VERSION 3.23)

# Set some basic project attributes
project (
	Snake
	VERSION 0.1
	DESCRIPTION "A Game Project"
	LANGUAGES CXX 
)
	
	
	
# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
	
	
	
# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")


add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)

# This project will output an executable file
add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/Game/Position.cpp
	src/Game/Board.cpp
	src/Game/Snake.cpp
	src/Game/Food.cpp
	src/Game/Game.cpp
	src/gui/Window.cpp
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          "${CMAKE_SOURCE_DIR}/assets/hello.jpg"
          "$<TARGET_FILE_DIR:${PROJECT_NAME}>/hello.jpg"
)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(${PROJECT_NAME} 
	PUBLIC 
		"${PROJECT_BINARY_DIR}"
	PRIVATE 
		${CMAKE_SOURCE_DIR}/src
)

# Link to the actual SDL3 library.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)