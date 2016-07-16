/**
 * LED Driver test
 *
 * This file is a part of project name.
 *
 * Copyright (c) 2016 Misha Tavkhelidze <misha.tavkhelidze@gmail.com>
 */

#include <unity.h>

void LED_Off_After_Create(void)
{
    TEST_FAIL_MESSAGE("Start here!");
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(LED_Off_After_Create);

    return UNITY_END();
}
