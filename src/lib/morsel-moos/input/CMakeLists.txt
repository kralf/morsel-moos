panda3d_interrogate(
  input
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_moos
)

remake_add_library(input LINK ${MORSEL_LIBRARIES})
remake_add_headers(INSTALL input)
