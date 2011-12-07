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

#include "moos_receiver.h"

#include <stdexcept>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

MOOSReceiver::MOOSReceiver(std::string name, MOOSClient& client, std::string
    msgName) :
  NodePath(name),
  mClient(&client) {
  if (!msgName.empty())
    mClient->subscribe(msgName, this);
}

MOOSReceiver::~MOOSReceiver() {
  mClient->unsubscribe(this);
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void MOOSReceiver::subscribe(const std::string& msgName) {
  mClient->subscribe(msgName, this);
}

void MOOSReceiver::unsubscribe(const std::string& msgName) {
  mClient->unsubscribe(msgName, this);
}

void MOOSReceiver::receive(const std::string& msgName, double msgTime, const
    std::string& msg) {
  throw std::runtime_error("Received unhandled string message");
}

void MOOSReceiver::receive(const std::string& msgName, double msgTime, const
    unsigned char* msgData, size_t msgSize) {
  throw std::runtime_error("Received unhandled binary message");
}
