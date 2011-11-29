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

#include <MOOSLIB/MOOSCommClient.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Receiver::Receiver(std::string name) :
  NodePath(name) {
  mComms = new CMOOSCommClient();
  mComms->SetOnConnectCallBack(onConnectCallback, this);
  mComms->SetOnDisconnectCallBack(onDisconnectCallback, this);
  mComms->Run("localhost", 9000, "MOOSPublisher", 10);
}

Receiver::~Receiver() {
  delete mComms;
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/


/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

bool Receiver::onConnectCallback(void* param) {
  return true;
}

bool Receiver::onDisconnectCallback(void* param) {
  Receiver* publisher = (Receiver*)param;
  publisher->mComms->Close();
  return true;
}
