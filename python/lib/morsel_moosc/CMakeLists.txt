panda3d_python_package(
  COMMAND ${PANDA3D_GEN_PYCODE_EXECUTABLE}
  NAME morsel_moos.morsel_moosc
)
remake_python_distribute(NAME morsel_moos.morsel_moosc PACKAGES
  morsel_moos.morsel_moosc DESCRIPTION "Python bindings")
