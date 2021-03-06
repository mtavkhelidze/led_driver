#ifndef _LED_DRIVE_H
#define _LED_DRIVE_H

void led_init(uint16_t* leds);
void led_turn_on(int lednum);
void led_turn_off(int lednum);
void led_turn_on_all();
int led_is_on(int lednum);
int led_is_off(int lednum);
void led_turn_off_all();
/* 1 -> off, 0 -> on */
void led_set_inverted(void);
/* Bit 16 -> pin 1, 15 -> 2, etc. */
void led_set_reversed(void);
void led_reset(void);
#endif /* _LED_DRIVE_H */
