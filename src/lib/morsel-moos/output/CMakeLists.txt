panda3d_interrogate(
  output
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_moos
)

remake_add_library(output LINK ${MORSEL_LIBRARIES})
remake_add_headers(INSTALL output)
