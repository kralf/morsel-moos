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

#include "publisher.h"

#include <stdexcept>

#include <MOOSLIB/MOOSCommClient.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Publisher::Publisher(std::string name, std::string msgName, std::string
  configFile) :
  MOOSClient(name, configFile),
  mMsgName(msgName) {
}

Publisher::~Publisher() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

bool Publisher::connectCallback() {
  return true;
}

bool Publisher::disconnectCallback() {
  return true;
}

void Publisher::publishString(std::string msg) {
  if (!mComms->Notify(mMsgName, msg, MOOSTime()))
    std::cerr << "Publisher::publishString(): failed to publish on MOOS"
      << std::endl;
}

void Publisher::publishBinary(unsigned char* data, size_t size) {
  if (!mComms->Notify(mMsgName, data, size, MOOSTime()))
    std::cerr << "Publisher::publishString(): failed to publish on MOOS"
      << std::endl;
}
