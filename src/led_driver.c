#include <stdint.h>
#include "led_driver.h"

static uint16_t *_leds;

void led_init(uint16_t *led)
{
    _leds = led;
    *_leds = 0;
}

void led_turn_on(uint8_t lednum)
{
    *_leds = 1;
}

void led_turn_off(uint8_t lednum)
{
    *_leds = 0;
}
