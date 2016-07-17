#include <unity_fixture.h>

TEST_GROUP_RUNNER(LED_Driver)
{
    RUN_TEST_CASE(LED_Driver, LED_Off_After_Create);
    RUN_TEST_CASE(LED_Driver, Turn_On_LED_One);
    RUN_TEST_CASE(LED_Driver, Turn_Off_LED_One);
    RUN_TEST_CASE(LED_Driver, Turn_On_Multiple_LEDs);
}
