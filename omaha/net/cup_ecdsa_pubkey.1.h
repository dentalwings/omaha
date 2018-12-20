// Copyright 2018 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ========================================================================
//
// CUP-ECDSA public keys consist of a byte array, 66 bytes long, containing:
// * The key ID (one byte)
// * The public key in X9.62 uncompressed encoding (65 bytes):
//     * Uncompressed header byte (0x04)
//     * Gx coordinate (256-bit integer, big-endian)
//     * Gy coordinate (256-bit integer, big-endian)
{0x01,
0x04,
0xb3, 0xc4, 0x9c, 0x53, 0xc9, 0x6d, 0x27, 0x32,
0xa2, 0x34, 0x71, 0x31, 0x38, 0xe0, 0xc4, 0x67,
0x34, 0x31, 0x43, 0xb8, 0xf1, 0xe0, 0xaa, 0xf7,
0xa8, 0x52, 0xa2, 0x59, 0xed, 0xd6, 0xe2, 0xf4,
0x74, 0xcc, 0xae, 0xf2, 0x14, 0xb9, 0xce, 0x0f,
0xa3, 0x48, 0x03, 0xc8, 0x5c, 0x9b, 0x14, 0x3d,
0xa6, 0xa8, 0x5f, 0xb4, 0x7e, 0x0f, 0x5e, 0x13,
0x36, 0x7f, 0x23, 0x9e, 0xc0, 0x3c, 0x52, 0xc6};
