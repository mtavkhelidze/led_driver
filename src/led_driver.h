#ifndef _LED_DRIVE_H
#define _LED_DRIVE_H

void led_init(uint16_t* leds);
void led_turn_on(int lednum);
void led_turn_off(int lednum);
void led_turn_on_all();

#endif /* _LED_DRIVE_H */
