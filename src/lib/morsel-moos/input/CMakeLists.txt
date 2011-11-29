panda3d_interrogate_include(
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_PANDA_HEADERS}/parser-inc
)
panda3d_interrogate(
  output
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  SOURCES ${REMAKE_PROJECT_SOURCE_DIR}/lib
  MODULE morsel_moos
)

remake_find_library(MOOS MOOSLIB/MOOSCommClient.h PACKAGE MOOS)
remake_find_library(MOOSGenLib MOOSGenLib/MOOSGenLib.h PACKAGE MOOSGenLib)

remake_include(${MOOS_HEADERS})

remake_add_library(input LINK ${MOOS_LIBRARY} ${MOOSGENLIB_LIBRARY})
remake_add_headers(INSTALL input)
