panda3d_interrogate_include(
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_PANDA_HEADERS}/parser-inc
)
panda3d_interrogate(
  client
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_moos
)

remake_add_library(client LINK ${MOOS_LIBRARY} ${MOOSGENLIB_LIBRARY})
remake_add_headers(INSTALL client)
