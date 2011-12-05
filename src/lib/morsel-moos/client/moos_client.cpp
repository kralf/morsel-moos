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

#include "morsel-moos/input/moos_receiver.h"

#include <stdexcept>

#include <MOOSLIB/MOOSCommClient.h>
#include <MOOSGenLib/ProcessConfigReader.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

MOOSClient::MOOSClient(std::string name, std::string configFile, std::string
    serverHost, unsigned int serverPort, unsigned int commTick) :
  NodePath(name),
  mConfigFile(configFile),
  mServerHost(serverHost),
  mServerPort(serverPort),
  mCommTick(commTick) {
  if (!mConfigFile.empty())
    parseConfigFile(mConfigFile, name);

  mComms = new CMOOSCommClient();
  mComms->SetOnConnectCallBack(onConnectCallback, this);
  mComms->SetOnDisconnectCallBack(onDisconnectCallback, this);
  mComms->Run(mServerHost.c_str(), mServerPort, name.c_str(), mCommTick);
}

MOOSClient::~MOOSClient() {
  delete mComms;
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

unsigned int MOOSClient::getCommTick() const {
  return mCommTick;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void MOOSClient::receive(double time) {
  MOOSMSG_LIST newMail;
  CMOOSMsg msg;
  
  if (mComms->Fetch(newMail)) {
    for (std::map<std::string, MOOSReceiver*>::const_iterator
        it = subscriptions.begin(); it != subscriptions.end(); ++it)
      if ((mComms->PeekMail(newMail, it->first, msg, true, true)) &&
        !msg.IsSkewed(MOOSTime())) {
      if (msg.IsDataType(MOOS_STRING))
        it->second->receive(it->first, msg.GetTime(), msg.GetString());
      else if (msg.IsDataType(MOOS_BINARY_STRING))
        it->second->receive(it->first, msg.GetTime(),
          reinterpret_cast<const unsigned char*>(msg.GetString().c_str()),
          msg.GetString().length());
    }
  }
}

void MOOSClient::subscribe(const std::string& msgName, MOOSReceiver*
    receiver) {
  std::map<std::string, MOOSReceiver*>::iterator it =
    subscriptions.find(msgName);

  if ((it == subscriptions.end()) || (it->second == receiver)) {
    subscriptions[msgName] = receiver;
    if (mComms->IsConnected() && !mComms->Register(msgName, 0))
      throw std::runtime_error("Failed to subscribe to message");
  }
  else
    throw std::runtime_error("Message already subscribed to");
}

void MOOSClient::unsubscribe(const std::string& msgName, MOOSReceiver*
    receiver) {
  std::map<std::string, MOOSReceiver*>::iterator it =
    subscriptions.find(msgName);

  if ((it != subscriptions.end()) && (it->second == receiver) &&
      mComms->UnRegister(it->first))
    subscriptions.erase(it);
  else
    throw std::runtime_error("Failed to unsubscribe from message");
}

void MOOSClient::unsubscribe(MOOSReceiver* receiver) {
  for (std::map<std::string, MOOSReceiver*>::iterator it =
      subscriptions.begin(); it != subscriptions.end(); ) {
    if (it->second == receiver) {
      if (mComms->UnRegister(it->first))
        subscriptions.erase(it++);
      else
        throw std::runtime_error("Failed to unsubscribe from message");
    }
    else
      ++it;
  }
}

void MOOSClient::publish(const std::string& msgName, const std::string& msg) {
  if (!mComms->Notify(msgName, msg, MOOSTime()))
    throw std::runtime_error("Failed to publish message");
}

void MOOSClient::publish(const std::string& msgName, unsigned char* msgData,
    size_t msgSize) {
  if (!mComms->Notify(msgName, msgData, msgSize, MOOSTime()))
    throw std::runtime_error("Failed to publish message");
}

bool MOOSClient::onConnectCallback(void* param) {
  MOOSClient* moosClient = (MOOSClient*)param;

  for (std::map<std::string, MOOSReceiver*>::const_iterator
      it = moosClient->subscriptions.begin();
      it != moosClient->subscriptions.end(); ++it)
    moosClient->subscribe(it->first, it->second);
  
  return true;
}

bool MOOSClient::onDisconnectCallback(void* param) {
  MOOSClient* moosClient = (MOOSClient*)param;
  
  if (!moosClient->mComms->Close())
    throw std::runtime_error("Failed to disconnect client");
  
  return true;
}

void MOOSClient::parseConfigFile(const std::string& configFile, const
  std::string& appName) {
  CProcessConfigReader configReader;
  configReader.SetAppName(appName);
  configReader.SetFile(configFile);
  
  if (!configReader.GetValue("ServerHost", mServerHost))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"ServerHost\" specified in config file");
  if (!configReader.GetValue("ServerPort", mServerPort))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"ServerPort\" specified in config file");
  if (!configReader.GetConfigurationParam("CommTick", mCommTick))
    throw std::runtime_error("MOOSClient::parseConfigFile(): "
      "configuration failure - no \"CommTick\" specified in config file");
}
