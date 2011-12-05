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

#ifndef MOOS_RECEIVER_H
#define MOOS_RECEIVER_H

/** \file moos_receiver.h
    \brief This file defines the Receiver class which is an interface for
           receiving from MOOS.
  */

#include "morsel-moos/client/moos_client.h"

#include <nodePath.h>

/** The Receiver class is an interface for receiving from MOOS.
    \brief MOOS receiver
  */
class MOOSReceiver :
  public NodePath {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  MOOSReceiver(std::string name, MOOSClient& client, std::string
    msgName = "");
  /// Destructor
  virtual ~MOOSReceiver();
  /** @}
    */

public:
  /** \name Public methods
    @{
    */
  /// Subscribe to message
  void subscribe(const std::string& msgName);
  /// Unsubscribe from message
  void unsubscribe(const std::string& msgName);
    
  /// Receive string message
  virtual void receive(const std::string& msgName, double msgTime,
    const std::string& msg);
  /// Receive binary message
  virtual void receive(const std::string& msgName, double msgTime,
    const unsigned char* msgData, size_t msgSize);
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// Client used by this receiver
  MOOSClient* mClient;
  /** @}
    */

};

#endif // MOOS_RECEIVER_H
