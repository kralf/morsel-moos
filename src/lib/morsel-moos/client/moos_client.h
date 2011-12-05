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

#ifndef MOOS_CLIENT_H
#define MOOS_CLIENT_H

/** \file moos_client.h
    \brief This file defines the MOOSClient class which is the abstract base
           class for any MOOS clients.
  */

#include <nodePath.h>

class CMOOSCommClient;

class MOOSReceiver;

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
  MOOSClient(std::string name, std::string configFile = "", std::string
    serverHost = "localhost", unsigned int serverPort = 9000,
    unsigned int commTick = 10);
  /// Destructor
  virtual ~MOOSClient();
  /** @}
    */

  /** \name Published accessors
    @{
    */
  /// Retrieve the comms frequency
  unsigned int getCommTick() const;
  /** @}
    */

  /** \name Published methods
    @{
    */
  /// Receive messages
  void receive(double time);
  /** @}
    */

public:
  /** \name Public methods
    @{
    */
  /// Subscribe to message
  void subscribe(const std::string& msgName, MOOSReceiver* receiver);
  /// Unsubscribe from message
  void unsubscribe(const std::string& msgName);
  /// Publish string message
  void publish(const std::string& msgName, const std::string& msg);
  /// Publish binary message
  void publish(const std::string& msgName, unsigned char* msgData,
    size_t msgSize);
  /** @}
    */

protected:
  /** \name Protected methods
    @{
    */
  /// Connect callback for MOOS
  static bool onConnectCallback(void* param);
  /// Disconnect callback for MOOS
  static bool onDisconnectCallback(void* param);
  /// Parse the configuration file and set the parameters
  void parseConfigFile(const std::string& config, const std::string& appName);
  /** @}
    */

  /** \name Protected members
    @{
    */
  /// Subscriptions
  std::map<std::string, MOOSReceiver*> subscriptions;
  /// Interface to MOOS
  CMOOSCommClient* mComms;
  /// Name of the MOOSDB machine to connect
  std::string mConfigFile;
  /// Name of the MOOSDB machine to connect
  std::string mServerHost;
  /// Port on which to connect
  unsigned int mServerPort;
  /// Communication loop frequency [Hz]
  unsigned int mCommTick;
  /** @}
    */

};

#endif // MOOS_CLIENT_H
