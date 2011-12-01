panda3d_interrogate_module(
  morsel_moosc
  COMMAND ${PANDA3D_INTERROGATE_MODULE_EXECUTABLE}
  MODULE morsel_moos
)

remake_add_library(
  morsel_moosc PREFIX panda3d- LINK moos output input ${PANDA3D_MORSELC_LIBRARY}
)
