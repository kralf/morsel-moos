from morsel.nodes import Node
from morsel_moos.moosc import MOOSClient as CMOOSClient

#-------------------------------------------------------------------------------

class MOOSClient(Node):
  def __init__(self, world, name = "MorselMOOS", configFile = "",
      serverHost = "localhost", serverPort = 9000, commTick = 10,
      quiet = True, **kargs):
    Node.__init__(self, world, name, **kargs)

    self.configFile = configFile
    self.serverHost = serverHost
    self.serverPort = serverPort
    self.commTick = commTick
    self.quiet = quiet

    self.client = CMOOSClient(name, self.configFile, self.serverHost,
      self.serverPort, self.commTick, self.quiet)
    self.client.reparentTo(self)

    framework.scheduler.addTask(name+"Receive", self.receive,
      1.0/self.client.getCommTick())

#-------------------------------------------------------------------------------

  def receive(self, time):
    self.client.receive(time)
    return True
