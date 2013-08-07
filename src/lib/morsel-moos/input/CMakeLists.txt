panda3d_interrogate(
  input
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_moos
)

remake_add_library(input)
remake_add_headers(INSTALL input LINK ${MORSEL_LIBRARIES})
