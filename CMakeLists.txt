cmake_minimum_required(VERSION 2.8)

project(scanner)


SET (CMAKE_BUILD_TYPE Debug)
SET (CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET (CMAKE_CXX_FLAGS "-std=c++11")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 依赖项
add_subdirectory(ExIconv)
add_subdirectory(Lex)

# bison and flex
if(UNIX)
	find_package(BISON)
	find_package(FLEX)
elseif(WIN32)
	#win32 use local bison and flex
	find_package(BISON PATHS ./win32/bison)
	find_package(FLEX PATHS ./win32/flex)
endif()

flex_target(SCANNER src/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp COMPILE_FLAGS -w)
bison_target(PARSER src/parser.y  ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

# src files and make exe
file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


include_directories(includes ${CMAKE_CURRENT_BINARY_DIR} src Lex/include third-party/cereal-1.1.2)

#win32 use local flex include
if(WIN32)
	include_directories(./win32/flex/include)
endif()

link_directories(${PROJECT_SOURCE_DIR}/lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/ExIconv/extlib/lib)

add_executable(maker ${source_files}
	${BISON_PARSER_OUTPUTS} ${FLEX_SCANNER_OUTPUTS}) # 使用动态库
TARGET_LINK_LIBRARIES(maker lex exiconv iconv charsetdetect charset)
