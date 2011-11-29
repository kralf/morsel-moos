from morsel.nodes import Output
from morsel_moos.morsel_moosc import Publisher as CPublisher

#-------------------------------------------------------------------------------

class Publisher(Output):
  def __init__(self, world, name, source, **kargs):
    Output.__init__(self, world, name, source, **kargs)

    self.output = CPublisher(name)
    self.output.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, period):
    self.output.publish(self.world.time)
    
