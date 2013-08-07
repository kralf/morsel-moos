panda3d_interrogate(
  client
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_moos
)

remake_add_library(client LINK ${MORSEL_LIBRARIES} ${MOOS_CORE_LIBRARIES})
remake_add_headers(INSTALL client)
