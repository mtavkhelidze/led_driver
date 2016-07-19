#include <stdint.h>

#include <runtime_error.h>

#include "led_driver.h"

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

enum {
    FIRST_LED = 1,
    LAST_LED = 16
};

static uint16_t *_leds;
static uint16_t _ledsimage;
static int _inverted;
static int _reversed;

static int _led_num_to_bit(int lednum)
{
    if(_reversed)
        lednum = 17 - lednum;
    return 1 << (lednum - 1);
}

static void _update_hardware(void)
{
    if(_inverted)
        *_leds = ~_ledsimage;
    else
        *_leds = _ledsimage;
}

static int _is_legal(int lednum)
{
    return (lednum >= FIRST_LED) && (lednum <= LAST_LED);
}

void led_init(uint16_t *led)
{
    _leds = led;
    _ledsimage = ALL_LEDS_OFF;
    _inverted = 0;
    _reversed = 0;
    _update_hardware();
}

void led_turn_on(int lednum)
{
    if(_is_legal(lednum)) {
        _ledsimage |= _led_num_to_bit(lednum);
        _update_hardware();
    } else
        RUNTIME_ERROR("LED Driver: out of bounds LED number", lednum);
}

void led_turn_off(int lednum)
{
    if(_is_legal(lednum)) {
        _ledsimage &= ~(_led_num_to_bit(lednum));
        _update_hardware();
    } else
        RUNTIME_ERROR("LED Driver: out of bounds LED number", lednum);
}

void led_turn_on_all(void)
{
    _ledsimage = ALL_LEDS_ON;
    _update_hardware();
}

int led_is_on(lednum)
{
    if(_is_legal(lednum))
        return _ledsimage & (_led_num_to_bit(lednum));
    return 0;
}

int led_is_off(lednum)
{
    return !led_is_on(lednum);
}

void led_turn_off_all(void)
{
    _ledsimage = ALL_LEDS_OFF;
    _update_hardware();
}

void led_set_inverted(void)
{
    _inverted = 1;
    _update_hardware();
}

void led_set_normal(void)
{
    _inverted = 0;
    _update_hardware();
}

void led_set_reversed(void)
{
    _reversed = 1;
    _update_hardware();
}
