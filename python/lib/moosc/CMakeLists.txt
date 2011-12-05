panda3d_python_package(
  COMMAND ${PANDA3D_GEN_PYCODE_EXECUTABLE}
  NAME morsel_moos.moosc
)
remake_python_distribute(NAME morsel_moos.moosc PACKAGES morsel_moos.moosc
  DESCRIPTION "Python bindings")
