cmake_minimum_required(VERSION 3.10)

set(PROJ_NAME "cmds_interpreter")
project(${PROJ_NAME})

add_subdirectory(plugin)

include_directories(${PROJECT_SOURCE_DIR}/inc)
add_executable(${PROJECT_NAME} 
  src/main.cpp
  src/LibInterface.cpp
  src/Set4LibInterfaces.cpp
  src/GeomObject.cpp
  src/ProgramInterpreter.cpp
  src/Scene.cpp
)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wl,-rpath=./plugin -rdynamic")
add_custom_command(TARGET ${PROJ_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo " Utworzony zostal program:  ${PROJ_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo ""
  )
