// Copyright 1996-2020 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Description:  Implement communication throught tcpip with the ROBOTIS OP2
 */

#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include <webots/types.h>

class Packet;

class Communication {
public:
  Communication();
  virtual ~Communication();

  bool initialize(const char *ip, int port);
  void close();

  bool isInitialized() const { return mSocket != -1; }

  bool sendPacket(const Packet *packet);
  bool receivePacket(Packet *packet);

private:
  int mSocket;
};

#endif
