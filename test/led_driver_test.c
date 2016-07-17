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

#include <unity.h>
#include <led_driver.h>

void LED_Off_After_Create(void)
{
    uint16_t leds = 0xffff;
    led_init(&leds);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

void Turn_On_LED_One(void)
{
    uint16_t leds;
    led_init(&leds);
    led_turn_on(1);
    TEST_ASSERT_EQUAL_HEX16(1, leds);
}

void Turn_Off_LED_One(void)
{
    uint16_t leds;
    led_init(&leds);
    led_turn_on(1);
    led_turn_off(1);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(LED_Off_After_Create);
    RUN_TEST(Turn_On_LED_One);
    RUN_TEST(Turn_Off_LED_One);

    return UNITY_END();
}
