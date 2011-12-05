from morsel_moos.client import *

#-------------------------------------------------------------------------------

def MOOSClient(**kargs):
  return framework.createInstance("client", type = "MOOSClient",
    world = framework.world, **kargs)
