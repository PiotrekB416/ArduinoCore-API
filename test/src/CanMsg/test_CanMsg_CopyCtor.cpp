/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <CanMsg.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace arduino;

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Test copy constructor", "[CanMsg-CopyCtor-01]")
{
  uint8_t const msg_data[4] = {0xDE, 0xAD, 0xC0, 0xDE};

  CanMsg const msg_1(CanStandardId(0x20), sizeof(msg_data), msg_data);
  CanMsg const msg_2(msg_1);

  REQUIRE(msg_1.data_length == msg_2.data_length);

  for (size_t i = 0; i < msg_1.data_length; i++)
  {
    REQUIRE(msg_1.data[i] == msg_data[i]);
    REQUIRE(msg_2.data[i] == msg_data[i]);
  }
}
