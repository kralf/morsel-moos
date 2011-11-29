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

#include <nodePath.h>

class CMOOSCommClient;

/** The Receiver class is an interface for receiving from MOOS.
    \brief MOOS receiver
  */
class Receiver :
  public NodePath {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  Receiver(std::string name);
  /// Destructor
  virtual ~Receiver();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Receive message from MOOS
  void receive(double time);
  /** @}
    */

public:

protected:
  /** \name Protected methods
    @{
    */
  /// Connect callback for MOOS
  static bool onConnectCallback(void*);
  /// Disconnect callback for MOOS
  static bool onDisconnectCallback(void*);
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Interface to MOOS
  CMOOSCommClient* mComms;
  /** @}
    */

};

#endif // RECEIVER_H
