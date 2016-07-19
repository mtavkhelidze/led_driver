#include <unity_fixture.h>

static void runAllTests(void)
{
    RUN_TEST_GROUP(LED_Driver);
    RUN_TEST_GROUP(LED_Driver_Inverted);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
