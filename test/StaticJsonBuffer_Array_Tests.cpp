// Copyright Benoit Blanchon 2014
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#include <gtest/gtest.h>
#include <ArduinoJson.h>

TEST(StaticJsonBuffer_Array_Tests, GrowsWithArray) {
  StaticJsonBuffer<JSON_ARRAY_SIZE(2)> json;

  JsonArray &array = json.createArray();
  ASSERT_EQ(JSON_ARRAY_SIZE(0), json.size());

  array.add("hello");
  ASSERT_EQ(JSON_ARRAY_SIZE(1), json.size());

  array.add("world");
  ASSERT_EQ(JSON_ARRAY_SIZE(2), json.size());
}

TEST(StaticJsonBuffer_Array_Tests, SucceedWhenBigEnough) {
  StaticJsonBuffer<JSON_ARRAY_SIZE(0)> json;

  JsonArray &array = json.createArray();
  ASSERT_TRUE(array.success());
}

TEST(StaticJsonBuffer_Array_Tests, FailsWhenTooSmall) {
  StaticJsonBuffer<JSON_ARRAY_SIZE(0) - 1> json;

  JsonArray &array = json.createArray();
  ASSERT_FALSE(array.success());
}

TEST(StaticJsonBuffer_Array_Tests, ArrayDoesntGrowWhenFull) {
  StaticJsonBuffer<JSON_ARRAY_SIZE(1)> json;

  JsonArray &array = json.createArray();
  array.add("hello");
  array.add("world");

  EXPECT_EQ(1, array.size());
}