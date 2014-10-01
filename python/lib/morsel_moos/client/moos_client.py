from morsel.nodes import Node
from morsel_moos.moosc import MOOSClient as CMOOSClient

#-------------------------------------------------------------------------------

class MOOSClient(Node):
  def __init__(self, configFile = "", serverHost = "localhost",
      serverPort = 9000, commTick = 10, quiet = True, **kargs):
    super(MOOSClient, self).__init__(**kargs)

    self.configFile = configFile
    self.serverHost = serverHost
    self.serverPort = serverPort
    self.commTick = commTick
    self.quiet = quiet

    self.client = CMOOSClient("CMOOSClient", self.configFile, self.serverHost,
      self.serverPort, self.commTick, self.quiet)
    self.client.reparentTo(self)

    framework.scheduler.addTask(self.name+"/Receive", self.receive,
      1.0/self.client.getCommTick())

#-------------------------------------------------------------------------------

  def receive(self, time):
    self.client.receive(time)
    return True
