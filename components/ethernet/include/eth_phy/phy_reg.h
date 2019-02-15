// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

/* This header contains register/bit masks for the standard
   PHY MII registers that should be supported by all PHY models.
*/

#define MII_BASIC_MODE_CONTROL_REG          (0x0)
#define MII_SOFTWARE_RESET                     BIT(15)

#define MII_BASIC_MODE_STATUS_REG           (0x1)
#define MII_AUTO_NEGOTIATION_COMPLETE          BIT(5)
#define MII_LINK_STATUS                        BIT(2)

#define MII_PHY_IDENTIFIER_1_REG              (0x2)
#define MII_PHY_IDENTIFIER_2_REG              (0x3)

//
// The PHY ID magic number is written to PHY ID 1 REG in phy_lan8720_init()
// after the default PHY ID has been verified.  Then in phy_mii_check_link_status()
// The PHY ID 1 REG is polled periodically to check if the magic number is still valid.
// If the magic number is no longer in PHY ID 1 REG, then the PHY is determined to
// have reset due to an unexpected reason.  If this happens, then the system is reset
// via ESP32 Task Watchdog Timer (TWDT).
//
#define MII_PHY_IDENTIFIER_1_MAGIC          (0xBEEF)

#define MII_AUTO_NEG_ADVERTISEMENT_REG      (0x4)
#define MII_ASM_DIR                            BIT(11)
#define MII_PAUSE                              BIT(10)

#define MII_PHY_LINK_PARTNER_ABILITY_REG    (0x5)
#define MII_PARTNER_ASM_DIR                    BIT(11)
#define MII_PARTNER_PAUSE                      BIT(10)
