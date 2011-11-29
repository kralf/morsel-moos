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

from morsel.nodes import Input
from morsel_moos.morsel_moosc import Receiver as CReceiver

#-------------------------------------------------------------------------------

class Receiver(Input):
  def __init__(self, world, name, source, **kargs):
    Input.__init__(self, world, name, source, **kargs)

    self.input = CReceiver(name)
    self.input.reparentTo(self)

#-------------------------------------------------------------------------------

  def inputData(self, period):
    self.input.receive(self.world.time)
