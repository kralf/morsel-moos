remake_find_package(panda3d CONFIG)
remake_find_package(morsel CONFIG)
remake_find_package(moos-core CONFIG)

remake_find_executable(panda3d-interrogate)
remake_find_executable(panda3d-interrogate_module)
remake_find_executable(panda3d-gen_pycode)

remake_include(
  lib metalib
  ${MORSEL_INCLUDE_DIRS}
  ${MOOS_CORE_INCLUDE_DIRS}
)
panda3d_interrogate_include(
  ${PANDA3D_INCLUDEDIR}
  ${PANDA3D_INCLUDEDIR}/parser-inc
)

remake_add_directories(lib)
remake_add_directories(metalib)
remake_pkg_config_generate(REQUIRES morsel)
