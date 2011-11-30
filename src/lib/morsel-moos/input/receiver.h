/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#ifndef RECEIVER_H
#define RECEIVER_H

/** \file receiver.h
    \brief This file defines the Receiver class which is an interface for
           receiving from MOOS.
  */

#include "morsel-moos/moos/moos_client.h"

class CMOOSMsg;

/** The Receiver class is an interface for receiving from MOOS.
    \brief MOOS receiver
  */
class Receiver :
  public MOOSClient {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  Receiver(std::string name, std::string msgName, std::string configFile = "");
  /// Destructor
  virtual ~Receiver();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Update method called by simulator
  void receive(double time);
  /** @}
    */

public:

protected:
  /** \name Protected methods
    @{
    */
  /// Connect callback
  virtual bool connectCallback();
  /// Disconnect callback
  virtual bool disconnectCallback();
  /// Handle the received MOOS message (to be implemented)
  virtual void receive(double time, const CMOOSMsg& msg) = 0;
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Message to which we listen
  std::string mMsgName;
  /** @}
    */

};

#endif // RECEIVER_H
