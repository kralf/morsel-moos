remake_find_library(MOOS MOOSLIB/MOOSCommClient.h PACKAGE MOOS)
remake_find_library(MOOSGenLib MOOSGenLib/MOOSGenLib.h PACKAGE MOOSGenLib)

remake_include(${MOOS_HEADERS})

remake_add_directories()
