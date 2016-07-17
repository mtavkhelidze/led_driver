#include <stdint.h>
#include "led_driver.h"

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static uint16_t *_leds;

static _led_num_to_bit(int lednum)
{
    return 1 << (lednum - 1);
}

void led_init(uint16_t *led)
{
    _leds = led;
    *_leds = ALL_LEDS_OFF;
}

void led_turn_on(int lednum)
{
    *_leds |= _led_num_to_bit(lednum);
}

void led_turn_off(int lednum)
{
    *_leds = 0;
}

void led_turn_on_all()
{
    *_leds = ALL_LEDS_ON;
}
