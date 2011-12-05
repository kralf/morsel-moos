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

#ifndef MOOSPUBLISHER_H
#define MOOSPUBLISHER_H

/** \file moos_publisher.h
    \brief This file defines the Publisher class which is an interface for
           publishing through MOOS.
  */

#include "morsel-moos/client/moos_client.h"

#include <nodePath.h>

/** The Publisher class is an interface for publishing through MOOS.
    \brief MOOS publisher
  */
class MOOSPublisher :
  public NodePath {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  MOOSPublisher(std::string name, MOOSClient& client, std::string msgName);
  /// Destructor
  virtual ~MOOSPublisher();
  /** @}
    */

protected:
  /** \name Protected methods
    @{
    */
  /// Publish a string to MOOS
  void publish(const std::string& msg);
  /// Publish binary data to MOOS
  void publish(unsigned char* data, size_t size);
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Client used by this publisher
  MOOSClient* mClient;
  /// Message which we publish
  std::string mMsgName;
  /** @}
    */

};

#endif // PUBLISHER_H
