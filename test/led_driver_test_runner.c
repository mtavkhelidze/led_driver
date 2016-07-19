#include <unity_fixture.h>

TEST_GROUP_RUNNER(LED_Driver)
{
    RUN_TEST_CASE(LED_Driver, LED_Off_After_Init);
    RUN_TEST_CASE(LED_Driver, Turn_On_LED_One);
    RUN_TEST_CASE(LED_Driver, Turn_Off_LED_One);
    RUN_TEST_CASE(LED_Driver, Turn_On_Multiple_LEDs);
    RUN_TEST_CASE(LED_Driver, Turn_Off_Any_LED);
    RUN_TEST_CASE(LED_Driver, Turn_All_LEDs_On);
    RUN_TEST_CASE(LED_Driver, LED_Memory_Is_Not_Readable);
    RUN_TEST_CASE(LED_Driver, Out_Of_Bounds_Change_Nothing);
    RUN_TEST_CASE(LED_Driver, Upper_And_Lower_Bounds);
    RUN_TEST_CASE(LED_Driver, Out_Of_Bounds_Turn_On_Does_No_Harm);
    RUN_TEST_CASE(LED_Driver, Out_Of_Bounds_Turn_Off_Does_No_Harm);
    RUN_TEST_CASE(LED_Driver, Out_Of_Bounds_Produces_Error);
    RUN_TEST_CASE(LED_Driver, LED_Is_On);
    RUN_TEST_CASE(LED_Driver, Out_Of_Bounds_LED_Is_Off);
    RUN_TEST_CASE(LED_Driver, LED_Is_Off);
    RUN_TEST_CASE(LED_Driver, Turn_Off_Multiple_LEDs);
    RUN_TEST_CASE(LED_Driver, Turn_All_Off);
    RUN_TEST_CASE(LED_Driver, Set_Inverted);
    RUN_TEST_CASE(LED_Driver, Set_Normal);
}

