/**
 * LED Driver test
 *
 * This file is a part of project name.
 *
 * Copyright (c) 2016 Misha Tavkhelidze <misha.tavkhelidze@gmail.com>
 */

/**
 * All 16 LEDs are off after the driver is initialized. A single LED can be
 * turned on.
 * 
 * A single LED can be turned off.
 *
 * Multiple LEDs can be turned on/off .
 *
 * Turn on all LEDs
 *
 * Turn off all LEDs
 *
 * Query LED state
 *
 * Check boundary values Check out-of-bounds values
 *
 */

#include <unity_fixture.h>
#include <led_driver.h>

TEST_GROUP(LED_Driver);

TEST_SETUP(LED_Driver)
{
}

TEST_TEAR_DOWN(LED_Driver)
{
}

TEST(LED_Driver, LED_Off_After_Create)
{
    uint16_t leds = 0xffff;
    led_init(&leds);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

TEST(LED_Driver, Turn_On_LED_One)
{
    uint16_t leds;
    led_init(&leds);
    led_turn_on(1);
    TEST_ASSERT_EQUAL_HEX16(1, leds);
}

TEST(LED_Driver, Turn_Off_LED_One)
{
    uint16_t leds;
    led_init(&leds);
    led_turn_on(1);
    led_turn_off(1);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}
