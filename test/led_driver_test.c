#include <unity_fixture.h>
#include <led_driver.h>

#include <runtime_error_mock.h>

TEST_GROUP(LED_Driver);

static uint16_t leds;

TEST_SETUP(LED_Driver)
{
    led_init(&leds);
}

TEST_TEAR_DOWN(LED_Driver)
{
}

TEST(LED_Driver, LED_Off_After_Init)
{
    uint16_t leds = 0xffff;
    led_init(&leds);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

TEST(LED_Driver, Turn_On_LED_One)
{
    led_turn_on(1);
    TEST_ASSERT_EQUAL_HEX16(1, leds);
}

TEST(LED_Driver, Turn_Off_LED_One)
{
    led_turn_on(1);
    led_turn_off(1);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

TEST(LED_Driver, Turn_On_Multiple_LEDs)
{
    led_turn_on(8);
    led_turn_on(9);
    TEST_ASSERT_EQUAL_HEX16(0x180, leds);
}

TEST(LED_Driver, Turn_Off_Any_LED)
{
    led_turn_on_all();
    led_turn_off(8);
    TEST_ASSERT_EQUAL_HEX16(0xff7f, leds);
}

TEST(LED_Driver, Turn_All_LEDs_On)
{
    led_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xffff, leds);
}

TEST(LED_Driver, LED_Memory_Is_Not_Readable)
{
    leds = 0xffff;
    led_turn_on(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, leds);
}

TEST(LED_Driver, Upper_And_Lower_Bounds)
{
    led_turn_on(1);
    led_turn_on(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, leds);
}

TEST(LED_Driver, Out_Of_Bounds_Change_Nothing)
{
    led_turn_on(-1);
    led_turn_on(0);
    led_turn_on(17);
    led_turn_on(100);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

TEST(LED_Driver, Out_Of_Bounds_Turn_On_Does_No_Harm)
{
    led_turn_on(-1);
    led_turn_on(0);
    led_turn_on(17);
    led_turn_on(100);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

TEST(LED_Driver, Out_Of_Bounds_Turn_Off_Does_No_Harm)
{
    led_turn_on_all();
    led_turn_off(-1);
    led_turn_off(0);
    led_turn_off(17);
    led_turn_off(100);
    TEST_ASSERT_EQUAL_HEX16(0xffff, leds);
}

TEST(LED_Driver, Out_Of_Bounds_Produces_Error)
{
    led_turn_on(-1);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out of bounds LED number",
                             runtime_error_mock_get_last_error());
    TEST_ASSERT_EQUAL(-1, runtime_error_mock_get_last_param());
}

TEST(LED_Driver, LED_Is_On)
{
    TEST_ASSERT_FALSE(led_is_on(11));
    led_turn_on(11);
    TEST_ASSERT_TRUE(led_is_on(11));
}

TEST(LED_Driver, Out_Of_Bounds_LED_Is_Off)
{
    TEST_ASSERT_FALSE(led_is_on(-1));
    TEST_ASSERT_FALSE(led_is_on(17));
    TEST_ASSERT_TRUE(led_is_off(-1));
    TEST_ASSERT_TRUE(led_is_off(17));
}

TEST(LED_Driver, LED_Is_Off)
{
    TEST_ASSERT_TRUE(led_is_off(1));
    led_turn_on(1);
    TEST_ASSERT_FALSE(led_is_off(1));
}

TEST(LED_Driver, Turn_Off_Multiple_LEDs)
{
    led_turn_on_all();
    led_turn_off(9);
    led_turn_off(8);
    TEST_ASSERT_EQUAL_HEX16((~0x180) & 0xffff, leds);
}

TEST(LED_Driver, Turn_All_Off)
{
    led_turn_on_all();
    led_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

/* Inverted LED logic support, i.e. when pin is 1 LED is off and vice
 * versa (exercise to Chapter 4).
 */
    
TEST(LED_Driver, Set_Inverted)
{
    led_set_inverted();
    TEST_ASSERT_EQUAL_HEX16(0xffff, leds);
}

TEST(LED_Driver, Inverted_Toggle)
{
    led_set_inverted();
    led_turn_on(1);
    led_turn_on(9);
    TEST_ASSERT_EQUAL_HEX16(0xfefe, leds);
}

/* Reversed pins on the board. 16 -> 1, 15 -> 2, 14 -> 3, etc..
 **/

TEST(LED_Driver, Set_Reversed_On)
{
    led_set_reversed();
    led_turn_on(1);
    led_turn_on(9);
    TEST_ASSERT_EQUAL_HEX16(0x8080, leds);
}

TEST(LED_Driver, Set_Reversed_Off)
{
    led_turn_on_all();
    led_set_reversed();
    led_turn_off(1);
    led_turn_off(9);
    TEST_ASSERT_EQUAL_HEX16(0x7f7f, leds);
}

TEST(LED_Driver, Set_Reversed_On_Off_Inverted)
{
    led_set_inverted();
    led_set_reversed();
    led_turn_on_all();
    led_turn_off(1);
    led_turn_off(9);
    TEST_ASSERT_EQUAL_HEX16(0x8080, leds);

}

TEST(LED_Driver, Reset)
{
    led_set_inverted();
    led_turn_on(1);
    TEST_ASSERT_EQUAL_HEX16(0x8000, leds);
    led_reset();
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds);
}
