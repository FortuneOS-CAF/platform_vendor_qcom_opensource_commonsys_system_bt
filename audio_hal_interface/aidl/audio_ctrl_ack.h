/*
 * Copyright 2022 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.

    * Redistribution and use in source and binary forms, with or without
      modification, are permitted (subject to the limitations in the
      disclaimer below) provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.

    * Neither the name of Qualcomm Innovation Center, Inc. nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
*/

#pragma once

namespace bluetooth {
namespace audio {
namespace aidl {

using ::aidl::android::hardware::bluetooth::audio::BluetoothAudioStatus;

enum class BluetoothAudioCtrlAck : uint8_t {
  SUCCESS_FINISHED = 0,
  PENDING,
  FAILURE_UNSUPPORTED,
  FAILURE_BUSY,
  FAILURE_DISCONNECTING,
  FAILURE
};

std::ostream& operator<<(std::ostream& os, const BluetoothAudioCtrlAck& ack);

inline BluetoothAudioStatus BluetoothAudioCtrlAckToHalStatus(
    const BluetoothAudioCtrlAck& ack) {
  switch (ack) {
    case BluetoothAudioCtrlAck::SUCCESS_FINISHED:
      return BluetoothAudioStatus::SUCCESS;
    case BluetoothAudioCtrlAck::FAILURE_UNSUPPORTED:
      return BluetoothAudioStatus::UNSUPPORTED_CODEC_CONFIGURATION;
    case BluetoothAudioCtrlAck::PENDING:
      return BluetoothAudioStatus::FAILURE;
    case BluetoothAudioCtrlAck::FAILURE_BUSY:
      return BluetoothAudioStatus::FAILURE;
    case BluetoothAudioCtrlAck::FAILURE_DISCONNECTING:
      return BluetoothAudioStatus::FAILURE;
    default:
      return BluetoothAudioStatus::FAILURE;
  }
}

}  // namespace aidl
}  // namespace audio
}  // namespace bluetooth