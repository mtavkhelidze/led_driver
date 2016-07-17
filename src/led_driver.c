#include <stdint.h>
#include "led_driver.h"

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static uint16_t *_leds;
static uint16_t _ledsimage;

static int _led_num_to_bit(int lednum)
{
    return 1 << (lednum - 1);
}

static void _update_hardware(void)
{
    *_leds = _ledsimage;
}

void led_init(uint16_t *led)
{
    _leds = led;
    _ledsimage = ALL_LEDS_OFF;
    _update_hardware();
}

void led_turn_on(int lednum)
{
    if(lednum > 0 && lednum <= 16) {
        _ledsimage |= _led_num_to_bit(lednum);
        _update_hardware();
    }
}

void led_turn_off(int lednum)
{
    if(lednum > 0 && lednum <= 16) {
        _ledsimage &= ~(_led_num_to_bit(lednum));
        _update_hardware();
    }
}

void led_turn_on_all()
{
    _ledsimage = ALL_LEDS_ON;
    _update_hardware();
}
