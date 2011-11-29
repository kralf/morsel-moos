################################################################################
# Copyright (C) 2011 by Jerome Maye                                            #
# jerome.maye@gmail.com                                                        #
#                                                                              #
# This program is free software; you can redistribute it and/or modify         #
# it under the terms of the Lesser GNU General Public License as published by  #
# the Free Software Foundation; either version 3 of the License, or            #
# (at your option) any later version.                                          #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# Lesser GNU General Public License for more details.                          #
#                                                                              #
# You should have received a copy of the Lesser GNU General Public License     #
# along with this program. If not, see <http://www.gnu.org/licenses/>.         #
################################################################################

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
