cmake_minimum_required(VERSION 2.6)

include(ReMake)
include(Panda3D)

remake_project(
  morsel-moos
  VERSION 0.1
  RELEASE alpha
  SUMMARY "Morsel MOOS bindings"
  AUTHOR "Jerome Maye"
  CONTACT "jerome.maye@mavt.ethz.ch"
  HOME "http://aslforge.ethz.ch/projects/morsel-moos"
  LICENSE "GNU Lesser General Public License (LGPL)"
  INSTALL /usr
)

remake_python()

remake_pack_deb(morsel)

remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
  morsel-dev
  morsel-moos
)

remake_doc(
  html
  latex
)

remake_pack_deb(
  COMPONENT python
  morsel-moos morsel-python
)
