cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
	URL "https://github.com/cpp-pm/hunter/archive/v0.23.240.tar.gz"
	SHA1 "ca19f3769e6c80cfdd19d8b12ba5102c27b074e0"
)

project(pass_gen) 

set(other_flags "${other_flags} -frtti -fvisibility-inlines-hidden")
set(other_flags "${other_flags} -fvisibility=hidden")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${other_flags}")

hunter_add_package(Boost COMPONENTS system filesystem program_options)
find_package(Boost CONFIG REQUIRED system filesystem program_options)

add_executable(
	${PROJECT_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/password.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/symbol.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/utils.cpp
)
target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
	${PROJECT_NAME}
	Boost::filesystem
	Boost::system
	Boost::program_options
)
