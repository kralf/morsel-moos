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

#ifndef MOOSCLIENT_H
#define MOOSCLIENT_H

/** \file moos_client.h
    \brief This file defines the MOOSClient class which is the abstract base
           class for any MOOS clients.
  */

#include <nodePath.h>

class CMOOSCommClient;

/** The MOOSClient class is the abstract base class for any MOOS clients.
    \brief MOOS client
  */
class MOOSClient :
  public NodePath {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  MOOSClient(std::string name, std::string configFile = "");
  /// Destructor
  virtual ~MOOSClient();
  /** @}
    */

public:

protected:
  /** \name Protected methods
    @{
    */
  /// Connect callback for MOOS
  static bool onConnectCallback(void* param);
  /// Disconnect callback for MOOS
  static bool onDisconnectCallback(void* param);
  /// Parse the configuration file and set the parameters
  void parseConfigFile(const std::string& config, const std::string& procName);
  /// Connect callback to be implemented
  virtual bool connectCallback() = 0;
  /// Disconnect callback to be implemented
  virtual bool disconnectCallback() = 0;
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Interface to MOOS
  CMOOSCommClient* mComms;
  /// Name of the MOOSDB machine to connect
  std::string mServerHost;
  /// Port on which to connect
  unsigned int mServerPort;
  /// Application loop frequency [Hz]
  unsigned int mAppTick;
  /// Communication loop frequency [Hz]
  unsigned int mCommTick;
  /// MOOS name
  std::string mMOOSName;
  /** @}
    */

};

#endif // MOOSCLIENT_H
