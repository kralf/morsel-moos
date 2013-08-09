cmake_minimum_required(VERSION 2.6)

include(ReMake)
include(Panda3D)

remake_project(
  morsel-moos
  VERSION 1.0
  RELEASE beta
  SUMMARY "MOOS bindings for the MObile Robot Simulator."
  AUTHOR "Ralf Kaestner"
  AUTHOR "Jerome Maye"
  CONTACT "ralf.kaestner@gmail.com"
  HOME "http://github.com/kralf/morsel-moos"
  LICENSE "GNU Lesser General Public License (LGPL)"
  INSTALL /usr
)

remake_add_directories(
  python
)
remake_doc(
  html
)

remake_pack_deb(
  DEPENDS morsel moos-core
)
remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "development headers"
  DEPENDS morsel-moos morsel-dev
)
remake_pack_deb(
  COMPONENT python
  DESCRIPTION "Python modules"
  DEPENDS morsel-moos morsel-python
)
remake_pack_deb(
  ARCH all
  COMPONENT doc
  DESCRIPTION "documentation"
)

remake_distribute_deb(
  DISTRIBUTION lucid
  SECTION python
  UPLOAD ppa:kralf/asl
  DEPENDS morsel-dev morsel-python moos-core-dev remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE MORSEL_MOOS_GIT_REVISION
)
remake_distribute_deb(
  DISTRIBUTION precise
  SECTION python
  UPLOAD ppa:kralf/asl
  DEPENDS morsel-dev morsel-python moos-core-dev remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE MORSEL_MOOS_GIT_REVISION
)
