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

#include "receiver.h"

#include <stdexcept>

#include <MOOSLIB/MOOSCommClient.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Receiver::Receiver(std::string name, std::string msgName, std::string
  configFile) :
  MOOSClient(name, configFile),
  mMsgName(msgName) {
}

Receiver::~Receiver() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

bool Receiver::connectCallback() {
  if (!mComms->Register(mMsgName, 0))
    throw std::runtime_error("Receiver::connectCallback: unable to register "
      "message");
  return true;
}

bool Receiver::disconnectCallback() {
  return true;
}

void Receiver::receive(double time) {
  MOOSMSG_LIST newMail;
  CMOOSMsg msg;
  if (mComms->Fetch(newMail)) {
    if (mComms->PeekMail(newMail, mMsgName, msg, true, true) == true) {
      if (!msg.IsSkewed(MOOSTime())) {
        receive(time, msg);
      }
    }
  }
}
