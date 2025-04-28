#
# You rarely need to edit this file. To add or remove files in your
# project edit the "src" folders contents and run `mulle-sde reflect`
#
#
# A convenient way to add a new source file is:
#    mulle-sde add src/foo.c
#
cmake_minimum_required( VERSION 3.13...99.99)

project( mulle-slug VERSION 0.0.4 LANGUAGES C)


set( MULLE_PROJECT_TYPE "Library")

### mulle-sde environment

# add cmake module paths to search path
list( INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake/share")
list( INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake/reflect")
list( INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include( Environment)

include( Files)

include( IDESupport OPTIONAL)


### Executable

include( Dependencies OPTIONAL)

set( EXECUTABLE_SOURCES ${SOURCES_NO_CLIB})
set( EXECUTABLE_NAME map-generator)

include( Executable OPTIONAL)

# use EXECUTABLE_COMPILE_TARGET for compiler options
target_compile_definitions( "${EXECUTABLE_COMPILE_TARGET}" PUBLIC)
target_compile_options( "${EXECUTABLE_COMPILE_TARGET}" PUBLIC)
# use EXECUTABLE_LINK_TARGET for linker options
if( LINK_PHASE)
   target_link_options( "${EXECUTABLE_LINK_TARGET}" PUBLIC)
endif()

add_custom_command(
   OUTPUT "src/map.inc"
   COMMAND map-generator > "src/map.inc"
   DEPENDS ${EXECUTABLE_LINK_TARGET}
   COMMENT "Create map.inc"
   WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
   VERBATIM
)


### Library

if( HEADER_PHASE)
   install( FILES ${INSTALL_PUBLIC_HEADERS}  DESTINATION "include/${PROJECT_NAME}")
   install( FILES ${INSTALL_PRIVATE_HEADERS} DESTINATION "include/${PROJECT_NAME}")
   install( FILES ${INSTALL_CMAKE_INCLUDES}          DESTINATION "include/${PROJECT_NAME}/cmake")

   # short cut out
   if( NOT COMPILE_PHASE AND NOT LINK_PHASE)
      return()
   endif()
endif()

if( LINK_PHASE)
endif()

set( LIBRARY_SOURCES ${SOURCES} "src/map.inc")

include( Library)

add_dependencies( ${LIBRARY_COMPILE_TARGET}
${EXECUTABLE_LINK_TARGET})


# use LIBRARY_COMPILE_TARGET for compiler options
target_compile_definitions( "${LIBRARY_COMPILE_TARGET}" PUBLIC)
target_compile_options( "${LIBRARY_COMPILE_TARGET}" PUBLIC)
if( NOT MSVC)
   target_compile_options( "${LIBRARY_COMPILE_TARGET}" PUBLIC -Wunused)
endif()

# use LIBRARY_LINK_TARGET for linker options
if( LINK_PHASE)
   target_link_options( "${LIBRARY_LINK_TARGET}" PUBLIC)
endif()

include( InstallLibrary)



include( FinalOutput OPTIONAL)
