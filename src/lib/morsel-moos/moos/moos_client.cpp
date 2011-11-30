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

#include "moos_client.h"

#include <stdexcept>

#include <MOOSLIB/MOOSCommClient.h>
#include <MOOSGenLib/ProcessConfigReader.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

MOOSClient::MOOSClient(std::string name, std::string configFile) :
  NodePath(name) {
  if (configFile.compare("") != 0)
    parseConfigFile(configFile, name);
  else {
    mServerHost = "localhost";
    mServerPort = 9000;
    mAppTick = 10;
    mCommTick = 10;
    mMOOSName = name;
  }
  mComms = new CMOOSCommClient();
  mComms->SetOnConnectCallBack(onConnectCallback, this);
  mComms->SetOnDisconnectCallBack(onDisconnectCallback, this);
  mComms->Run(mServerHost.c_str(), mServerPort, mMOOSName.c_str(), mCommTick);
}

MOOSClient::~MOOSClient() {
  delete mComms;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

bool MOOSClient::onConnectCallback(void* param) {
  MOOSClient* moosClient = (MOOSClient*)param;
  return moosClient->connectCallback();
}

bool MOOSClient::onDisconnectCallback(void* param) {
  MOOSClient* moosClient = (MOOSClient*)param;
  if (!moosClient->mComms->Close())
    throw std::runtime_error("MOOSClient::onDisconnectCallback: unable to "
      "disconnect");
  return moosClient->disconnectCallback();
}

void MOOSClient::parseConfigFile(const std::string& configFile, const
  std::string& procName) {
  CProcessConfigReader configReader;
  configReader.SetAppName(procName);
  configReader.SetFile(configFile);
  if (!configReader.GetValue("ServerHost", mServerHost))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"ServerHost\" specified in config file");
  if (!configReader.GetValue("ServerPort", mServerPort))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"ServerPort\" specified in config file");
  if (!configReader.GetConfigurationParam("MOOSName", mMOOSName))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"MOOSName\" specified in config file");
  if (!configReader.GetConfigurationParam("AppTick", mAppTick))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"AppTick\" specified in config file");
  if (!configReader.GetConfigurationParam("CommTick", mCommTick))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"CommTick\" specified in config file");
}
