/******************************************************************************
 * Copyright (C) 2011 by Ralf Kaestner and Jerome Maye                        *
 * ralf.kaestner@gmail.com                                                    *
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

#include "moos_publisher.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

MOOSPublisher::MOOSPublisher(std::string name, MOOSClient& client) :
  NodePath(name),
  mClient(&client) {
}

MOOSPublisher::~MOOSPublisher() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void MOOSPublisher::publish(const std::string& msgName, const std::string&
    msg) {
  mClient->publish(msgName, msg);
}

void MOOSPublisher::publish(const std::string& msgName, unsigned char* msgData,
    size_t msgSize) {
  mClient->publish(msgName, msgData, msgSize);
}
