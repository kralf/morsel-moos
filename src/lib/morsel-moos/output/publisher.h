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

#ifndef PUBLISHER_H
#define PUBLISHER_H

/** \file publisher.h
    \brief This file defines the Publisher class which is an interface for
           publishing through MOOS.
  */

#include "morsel-moos/moos/moos_client.h"

/** The Publisher class is an interface for publishing through MOOS.
    \brief MOOS publisher
  */
class Publisher :
  public MOOSClient {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  Publisher(std::string name, std::string msgName, std::string configFile = "");
  /// Destructor
  virtual ~Publisher();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Update method called by simulator
  virtual void publish(double time) = 0;
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
  /// Publish a string to MOOS
  bool publishString(std::string msg);
  /// Publish binary data to MOOS
  bool publishBinary(unsigned char* data, size_t size);
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Message which we publish
  std::string mMsgName;
  /** @}
    */

};

#endif // PUBLISHER_H
