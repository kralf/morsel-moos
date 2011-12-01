panda3d_interrogate_include(
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_PANDA_HEADERS}/parser-inc
)
panda3d_interrogate(
  moos
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  SOURCES ${REMAKE_PROJECT_SOURCE_DIR}/lib
  MODULE morsel_moos
)

remake_add_library(moos LINK ${MOOS_LIBRARY} ${MOOSGENLIB_LIBRARY})
remake_add_headers(INSTALL moos)
